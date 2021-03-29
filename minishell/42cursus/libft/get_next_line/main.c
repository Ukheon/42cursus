#include <stdio.h>
#include "get_next_line.h"
#include "../libft/libft.h"
#include <string.h>
#include <sys/wait.h>

void	unset_list(t_list **head, char *str)
{
	t_list *temp;
	t_list *temp2;
	t_list *prev;

	temp = *head;
	while (temp->next)
	{
		if ((ft_strncmp(temp->key, str, ft_strlen(temp->key)) == 0))
		{
			temp2 = temp->next;
			prev->next = temp2;
			ft_lstdelone(temp, free);
		}
		prev = temp;
		temp = temp->next;
	}
}

void	check_list(t_list *head)
{
	t_list *temp;

	while (head->next)
	{
		printf("%s%c%s\n",head->key, '=', head->value);
		head = (head)->next;
	}
}


void	init_list(t_list **head, char *envp[])
{
	int			i;

	i = 0;
	while (envp[i])
	{
		ft_lstadd_back(head, ft_lstnew(envp[i]));
		i++;
	}
}

int main(int argc, char *argv[], char *envp[])
{
	t_list *head;
	int len;
	
	head = NULL;
	init_list(&head, envp);
	len = ft_lstsize(head);
	printf("%d\n\n",len);
	check_list(head);
	unset_list(&head, "hi");
	len = ft_lstsize(head);
	printf("%d\n\n",len);
	char *str;
	while (head->next)
	{
		printf("%s=%s\n",head->key, head->value);
		head = head->next;
	}
	int fd;
	char *line;
	int id;
	int stay;
	int i = 0;
	fd = 0;
	int ret;
	(void)argv;
	write(1, "$>", 2);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (strncmp(line, "ls", 2) == 0)
		{
			
			id = fork();
			if (id != 0)
			{
				printf("parent here ? \n");
				wait(&id);
				printf("parent id %d\n", id);
			}
			else if (id == 0)
			{
				execve("/bin/ls",argv, envp);
				exit(0);
			}
		}

		if (strncmp(line, "cat ", 4) == 0)
		{
			char *str;
			int a;
			char *l;
			str = strchr(line, ' ');
			a = open(str + 1, O_RDONLY);
			while (get_next_line(a, &l) > 0)
			{
				printf("%s\n", l);
			}
			printf("%s\n", l);
		}
		write(1, "$>", 2);
	}
	return (0);
}
