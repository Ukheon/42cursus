/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:50:09 by ukwon             #+#    #+#             */
/*   Updated: 2021/04/26 16:02:02 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int				nbr_length(int n)
{
	int		i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void			delete_end(void)
{
	int		save;

	g_info.c = 0;
	if (g_info.col <= 3 || g_info.idx <= 0)
		return ;
	save = (int)ft_strlen(g_info.buf) - 1;
	g_info.col--;
	g_info.idx--;
	g_info.buf[save] = '\0';
	tputs(tgoto(g_info.cm, g_info.col, g_info.row), 1, putchar_tc);
	tputs(g_info.ce, 1, putchar_tc);
}

void			get_cursor_position(long long int *col, \
long long int *rows, int i, int a)
{
	char	buf[255];
	int		ret;
	char	temp;

	write(0, "\033[6n", 4);
	ret = read(0, buf, 254);
	buf[ret] = '\0';
	while (buf[i])
	{
		if (buf[i] >= '0' && buf[i] <= '9')
		{
			if (a == 0)
				*rows = ft_atoi(&buf[i]) - 1;
			else
			{
				temp = ft_atoi(&buf[i]);
				*col = temp - 1;
			}
			a++;
			i += nbr_length(temp) - 1;
		}
		i++;
	}
}
