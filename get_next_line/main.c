#include <stdio.h>
#include "get_next_line.h"
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char *envp[])
{
	int fd;
	char *line;
	int id;
	int stay;
	int i = 0;
	fd = 0;
	int ret;
	(void)argv;
	write(1, "minishell$", 10);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (strncmp(line, "ls", 2) == 0)
		{
			printf("before : %d\n",id);
			id = fork();
			if (id != 0)
			{
				wait(&id);
			}
			if (id == 0)
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
		write(1, "minishell$", 10);
	}
	return (0);
}