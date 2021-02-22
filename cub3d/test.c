#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

//
typedef struct	s_line
{
	char		*data;
	struct s_line *next;
}				t_line;

void	add_data_list(struct s_line *target, char *str)
{
	t_line *newnode;
	newnode = (t_line *)malloc(sizeof(t_line));
	while (target->next)
		target = target->next;
	newnode->next = target->next;
	newnode->data = str;
	target->next = newnode;
	
}

int		main(void)
{
	t_line *head;
	head = (t_line *)malloc(sizeof(t_line));
	head->next = NULL;
	t_line *check;
	
	add_data_list(head,"abcdefg");
	add_data_list(head,"hijk");
	add_data_list(head,"opqr");
	add_data_list(head,"stu");
	check = head->next;
	while (check != NULL)
	{
		printf("%s\n",check->data);
		check = check->next;
	}
}
