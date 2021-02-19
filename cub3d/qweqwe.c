#include <stdio.h>
#include <math.h>
#include "./include/libft.h"

int				ft_strncmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (int)(str1[i] - str2[i]);
		}
		i++;
	}
	return (int)(str1[i] - str2[i]);
}

static int		col_size(char const *s1, char c)
{
	char	*str;
	int		len;
	int		i;

	if (!s1)
		return (0);
	len = 0;
	str = (char *)s1;
	i = 0;
	while (str[i] != c && str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static int		row_size(char const *s1, char c)
{
	int		check;
	int		len;
	int		last;

	if (!*s1)
		return (0);
	last = 0;
	while (s1[last])
		last++;
	last--;
	while (s1[last] == c)
		last--;
	len = 0;
	check = 0;
	while (*s1 == c)
		s1++;
	while (*s1 && last-- != 0)
	{
		if (*s1 == c && check++ == 0)
			len++;
		else
			check = 0;
		s1++;
	}
	return (len + 1);
}

size_t			ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			len;

	len = 0;
	if (dst == 0 && src == 0)
		return (0);
	if (size == 0)
	{
		while (src[len])
			len++;
		return (len);
	}
	i = 0;
	while (size - 1 > 0 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
		size--;
	}
	dst[i] = '\0';
	while (src[len])
		len++;
	return (len);
}


char			**ft_split(char const *s, char c)
{
	int			len;
	char		**res;
	int			row;

	row = 0;
	len = row_size(s, c);
	if (!s || !(res = (char **)malloc(sizeof(char *) * (len + 1))))
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		len = col_size(s, c);
		if (!(res[row] = (char *)malloc(sizeof(char) * len + 1)))
			return (0);
		ft_strlcpy(res[row], s, len + 1);
		row++;
		while (*s != c && *s != '\0')
			s++;
	}
	res[row] = NULL;
	return (res);
}


static int		ft_whitespace(char str)
{
	if ((str >= 9 && str <= 13) || str == ' ' || str == '\0')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	long long int		num;
	int					i;
	int					sign;

	sign = 1;
	i = 0;
	num = 0;
	while (str[i] && ft_whitespace(str[i]) == 1)
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
		if ((num * sign) <= -2147483649)
			return (0);
		else if ((num * sign) >= 2147483648)
			return (-1);
	}
	return (num * sign);
}


int			main(void)
{
	int		a;
	int		num;

	num = 0;
	char **save;
	int res;
	res = 0;
	int idx = 2;
	char *data;
			
	data = "255,99,11";
	save = ft_split(data, ',');

	for (int i = 0; i < 6; i++)
	{
		num = ft_atoi(save[idx--]);
		// printf("i = %d\n",i);
		res += num % 16 * pow(16,i);
			// printf("why?\n");
		printf("%d \n",res);
		i++;
		// printf("i = %d\n",i);
		res += num / 16 * pow(16,i);
		// printf("%d\n",res);
		printf("%d \n",res);
	}
	// str = "abcdefg";
	// str1 = "abcdefg";
	// if (!(ft_strncmp(str,"abcdefg")))
	// {
	// 	printf("why?\n");
	// 	printf("%s %s\n", "abcdefg", str);
	// }
	return (0);
}