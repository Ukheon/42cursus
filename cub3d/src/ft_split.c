/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 15:45:18 by ukheon            #+#    #+#             */
/*   Updated: 2021/02/24 01:22:18 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int		check_sep(char const c, char *sep)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	while (i < ft_strlen(sep))
	{
		if (c == sep[i])
			check++;
		i++;
	}
	if (check >= 1)
		return (1);
	return (0);
}

static int		col_size(char const *s1, char *sep)
{
	char	*str;
	int		len;
	int		i;

	if (!s1)
		return (0);
	len = 0;
	str = (char *)s1;
	i = 0;
	while (!(check_sep(str[i], sep)) && str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static int		row_size(char const *s1, char *sep)
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
	while (check_sep(s1[last], sep))
		last--;
	len = 0;
	check = 0;
	while (check_sep(s1[last], sep))
		s1++;
	while (*s1 && last-- != 0)
	{
		if (check_sep(*s1, sep) && check++ == 0)
			len++;
		else
			check = 0;
		s1++;
	}
	return (len + 1);
}

char			**ft_split(char const *s, char *sep, t_zip *zip)
{
	int			len;
	char		**res;
	int			row;

	row = 0;
	len = row_size(s, sep);
	zip->row_check = len;
	if (!s || !(res = (char **)malloc(sizeof(char *) * (len + 1))))
		return (0);
	while (*s)
	{
		while (check_sep(*s, sep))
			s++;
		if (*s == '\0')
			break ;
		len = col_size(s, sep);
		if (!(res[row] = (char *)malloc(sizeof(char) * len + 1)))
			return (0);
		ft_strlcpy(res[row], s, len + 1);
		row++;
		while (!(check_sep(*s, sep)) && *s != '\0')
			s++;
	}
	res[row] = NULL;
	return (res);
}
