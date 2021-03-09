/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 15:45:18 by ukheon            #+#    #+#             */
/*   Updated: 2021/03/09 16:15:46 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

static void		check_split(char **res, t_zip *zip)
{
	int			i;

	i = 0;
	zip->row = 0;
	while (res[i])
		i++;
	zip->row = i;
}

char			**ft_split(char const *s, char c, t_zip *zip)
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
	check_split(res, zip);
	return (res);
}
