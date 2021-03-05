/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:46:53 by ukwon             #+#    #+#             */
/*   Updated: 2021/03/05 11:52:17 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		parsing_error(t_zip *zip)
{
	if (*zip->split)
		return (0);
	if (!(*zip->split) && zip->check == 8 && zip->height_size > 0)
		cub3d_error("empty line in map . . . . ? ? ? ? ? ! ! !");
	return (1);
}

void	cub_file_check(int argc, char *str)
{
	char *c;

	if (argc >= 2 && argc <= 3)
	{
		c = ft_strnstr(str, ".cub", ft_strlen(str));
		if (c == 0 || ft_strlen(c) != 4)
		{
			cub3d_error("cub file error!");
		}
	}
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t l_len;
	size_t b_len;
	size_t size;

	b_len = ft_strlen((char *)big);
	l_len = ft_strlen((char *)little);
	if (b_len < l_len || len < l_len)
		return (0);
	size = b_len > len ? len : b_len;
	while (size-- >= l_len)
	{
		if (ft_strcmp(big, little) == 0)
			return ((char *)big);
		big++;
	}
	return (0);
}
