/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:15:53 by hyeolee           #+#    #+#             */
/*   Updated: 2021/05/01 13:42:12 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char			*join_char(char *dst, char src)
{
	int			dst_len;
	int			i;
	char		*ret;

	if (!dst)
		dst = ft_strdup("");
	dst_len = ft_strlen(dst);
	ret = malloc(sizeof(char *) * (dst_len + 2));
	if (!ret)
		return (NULL);
	i = 0;
	while (dst[i])
	{
		ret[i] = dst[i];
		i++;
	}
	ret[i] = src;
	i++;
	ret[i] = 0;
	free(dst);
	return (ret);
}

void			change_to_space(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == -1)
			str[i] = ' ';
		if (str[i] == -2)
			str[i] = '|';
		i++;
	}
}

void			parser_init(t_var *parser)
{
	parser->start_idx = 0;
	parser->end_idx = 0;
	parser->redir_len = 0;
}

char			*join_str(char *dst, char *src)
{
	char		*temp;

	if (!dst)
		dst = ft_strdup("");
	if (!src)
		return (dst);
	temp = ft_strjoin(dst, src);
	free(dst);
	return (temp);
}

int				ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
		{
			return (int)(str1[i] - str2[i]);
		}
		i++;
	}
	return (int)(str1[i] - str2[i]);
}
