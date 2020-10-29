/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:52:31 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/29 20:58:08 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*putstr(char *res, int n, int len)
{
	long long int	swap;

	swap = n;
	if (swap == 0)
	{
		res[0] = 0 + '0';
		return (res);
	}
	else if (swap < 0)
	{
		res[0] = '-';
		len += 1;
		swap *= -1;
	}
	while (swap)
	{
		res[len] = (swap % 10) + '0';
		swap = swap / 10;
		len--;
	}
	return (res);
}

char			*ft_itoa(int n)
{
	char	*res;
	int		save_n;
	int		len;
	int		check;

	check = 0;
	len = 0;
	save_n = n;
	if (n == 0)
		len = 1;
	if (save_n < 0)
	{
		check = 1;
		save_n *= -1;
	}
	while (save_n)
	{
		save_n = save_n / 10;
		len++;
	}
	if (!(res = (char *)malloc(sizeof(char) * (len + check + 1))))
		return (0);
	res = putstr(res, n, len - 1);
	res[len + check] = '\0';
	return (res);
}

char			*ft_strdup(const char *s1)
{
	int		i;
	char	*res;
	char	*str;

	str = (char *)s1;
	i = 0;
	while (str[i])
		i++;
	if (!(res = (char *)malloc(sizeof(char) * i + 1)))
		return (0);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	int				i;
	char			*str;
	int				s_len;

	if (!s)
		return (NULL);
	s_len = 0;
	str = (char *)s;
	while (str[s_len])
		s_len++;
	if ((int)start > (int)ft_strlen(str))
		return (ft_strdup(""));
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (len--)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
