#include <stdio.h>
#include <string.h>

char		*ft_strcpy(char *dest, char *src);

int			main(void)
{
	char *s;
	char dest[50];
	char src[50] = "Copy this";
	ft_strcpy(dest, src);
	printf("%s\n", dest);
	return (0);
}
