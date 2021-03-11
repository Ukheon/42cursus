#include <stdio.h>
#include <string.h>
#include <unistd.h>

int			ft_strcmp(char *dest, char *src);
int			ft_write(int fd, char *str, int d);

int			main(void)
{
	int ret;

	ret = ft_write(1, "1\n", 2);
	printf("%d\n",ret);
	return (0);
}
