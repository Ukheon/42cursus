/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:50:17 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/02 15:14:34 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_list			*new_history(char *str)
{
	t_list	*new;

	if (!str)
		return (0);
	new = (t_list *)malloc(sizeof(t_list) * 1);
	if (!new)
		return (0);
	new->history = ft_strdup(str);
	new->filename = NULL;
	new->redir = NULL;
	new->key = NULL;
	new->value = NULL;
	new->next = NULL;
	return (new);
}

int				history_error_check(t_list **history)
{
	if ((g_info.his_idx > ft_lstsize(*history)))
	{
		g_info.his_idx = ft_lstsize(*history);
		return (1);
	}
	if ((g_info.his_idx < 1))
	{
		if (g_info.first_flag == 1 || g_info.history_flag == 0)
		{
			g_info.idx = 0;
			ft_memset(g_info.buf, 0, (int)ft_strlen(g_info.buf));
			g_info.col = 3;
			g_info.his_idx = 0;
			tputs(tgoto(g_info.cm, 3, g_info.row), 1, putchar_tc);
			tputs(g_info.ce, 1, putchar_tc);
			write(0, &g_info.buf, (int)ft_strlen(g_info.buf));
			return (1);
		}
		g_info.his_idx = 1;
		g_info.first_flag = 1;
	}
	if (!(*history))
		return (1);
	return (0);
}

void			exec_history(t_list **history, int save, char *history_data)
{
	t_list	*temp;

	temp = *history;
	while (temp->next && save--)
		temp = temp->next;
	history_data = ft_strdup(g_info.buf);
	ft_memset(g_info.buf, 0, (int)ft_strlen(g_info.buf));
	ft_strlcpy(g_info.buf, temp->history, (int)ft_strlen(temp->history) + 1);
	tputs(tgoto(g_info.cm, 3, g_info.row), 1, putchar_tc);
	tputs(g_info.ce, 1, putchar_tc);
	write(0, &g_info.buf, (int)ft_strlen(g_info.buf));
	g_info.col = (int)ft_strlen(g_info.buf) + 3;
	g_info.idx = (int)ft_strlen(g_info.buf);
	if (g_info.history_flag == 0)
	{
		if (g_info.write_flag == 1)
		{
			g_info.his_idx = 1;
			ft_lstadd_front(history, new_history(history_data));
			g_info.history_flag = 1;
		}
	}
	if (g_info.his_idx < 0)
		g_info.his_idx = 0;
	free(history_data);
}

void			call_history(t_list **history)
{
	char	*history_data;
	int		save;

	history_data = NULL;
	g_info.c = 0;
	if (history_error_check(history))
		return ;
	save = g_info.his_idx - 1;
	exec_history(history, save, history_data);
}
