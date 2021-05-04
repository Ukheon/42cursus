/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:50:28 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/02 13:07:37 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void			set_pipe(t_list **head)
{
	g_info.pipe_flag--;
	g_info.enter_flag = 1;
	g_info.error = 0;
	g_info.env = fill_env_data(head);
	ft_memset(g_info.buf, 0, 4096);
}

void			set_fd(void)
{
	g_info.signal_flag = 1;
	pipe(g_info.fds);
	pipe(g_info.dfs);
}

void			parent_wait(void)
{
	close(g_info.fds[0]);
	close(g_info.fds[1]);
	close(g_info.dfs[1]);
	wait(&g_info.status);
}

void			set_child_dup(void)
{
	if (g_info.fd_flag == 1)
		dup2(g_info.fd_storage[0], g_info.fds[0]);
	dup2(g_info.fds[0], 0);
	dup2(g_info.dfs[1], 1);
	close(g_info.fds[0]);
	close(g_info.dfs[0]);
	if (g_info.check > 1)
		close(g_info.fds[1]);
}
