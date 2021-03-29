#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

int			ft_strlen(char *str);
char		*ft_strcpy(char *dest, char *src);
int			ft_strcmp(char *src1, char *src2);
int			ft_write(int fd, char *str, int len);
int			ft_read(int fd, char *str, int len);
char		*ft_strdup(const char *str);

int			main(void)
{

	int		ret;
	int		fd;
	int		i;
	int		len;
	char	*buf;
	char	*str = "here input char*";
	char	dest[4096];
	char	*cmpA = "abcdef";
	char	*cmpB = "abcdeg";

	ret = ft_strlen(str);
	printf("\n첫번째 파일 ft_strlen입니다. ---------\n");
	printf("ft_strlen : %d\n", ret);
	ret = strlen(str);
	printf("strlen : %d\n", ret);
	printf("\n두번째 파일 ft_strcpy입니다. ---------\n");
	ft_strcpy(dest, str);
	printf("ft_strcpy : %s\n", dest);
	strcpy(dest, str);
	printf("strcpy : %s\n", dest);
	printf("\n세번째 파일 ft_strcmp입니다. ---------\n");
	ret = ft_strcmp(cmpA, cmpB);
	printf("ft_strcmp : %d\n", ret);
	ret = strcmp(cmpA, cmpB);
	printf("strcmp : %d\n", ret);
	printf("\n네번째 파일 ft_write입니다. ---------\n");
	ft_write(1, "ft_write = hi\n", 14);
	write(1, "write = hi\n", 11);
	printf("\n다섯번째파일 ft_read입니다. ---------\n");
	i = 0;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (i < BUFFER_SIZE)
		buf[i++] = '\0';
	fd = open("txt.txt", O_RDONLY);
	ret = ft_read(fd, buf, BUFFER_SIZE);
	printf("ft_read : %s ret = %d\n", buf, ret);
	free(buf);
	i = 0;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (i < BUFFER_SIZE)
		buf[i++] = '\0';
	fd = open("txt.txt", O_RDONLY);
	ret = read(fd, buf, BUFFER_SIZE);
	printf("read : %s ret = %d\n",buf, ret);
	free(buf);

	printf("\n마지막파일 ft_strdup입니다. ---------\n");
	buf = ft_strdup("12345");
	printf("%s\n",buf);
	free(buf);
	buf = strdup("12345");
	printf("%s\n",buf);
	free(buf);
	printf("끝 !\n");
	return (0);
}
