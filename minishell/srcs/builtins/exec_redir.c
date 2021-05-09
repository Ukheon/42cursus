/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:49:49 by ukwon             #+#    #+#             */
/*   Updated: 2021/04/27 18:28:09 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void			only_exist_right(t_token **tokens, t_list **head)
{
	g_info.redir_stop = 1;
	if (g_info.pipe_flag == 0)
	{
		g_info.pipe_flag = 2;
		start_pipe(tokens, head);
		ft_memset(g_info.buf, 0, 4096);
		read(g_info.fd_storage[0], g_info.buf, 4096);
		close(g_info.fd_storage[0]);
		write(g_info.right_fd, g_info.buf, ft_strlen(g_info.buf));
	}
	else
	{
		if (g_info.pipe_flag == 1)
			g_info.pipe_flag++;
		start_pipe(tokens, head);
		ft_memset(g_info.buf, 0, 4096);
		read(g_info.fd_storage[0], g_info.buf, 4096);
		close(g_info.fd_storage[0]);
		write(g_info.right_fd, g_info.buf, ft_strlen(g_info.buf));
	}
}

int				only_exist_left(t_token **tokens, t_list **head)
{
	if (g_info.pipe_flag == 0 || g_info.pipe_flag == 1)
	{
		g_info.redir_stop = 0;
		g_info.fd_flag = 1;
		g_info.fd_storage[0] = dup(g_info.left_fd);
		g_info.pipe_flag = 1;
		start_pipe(tokens, head);
		ft_memset(g_info.buf, 0, 4096);
		read(g_info.fd_storage[0], g_info.buf, 4096);
		close(g_info.fd_storage[0]);
		write(1, g_info.buf, ft_strlen(g_info.buf));
	}
	else
	{
		g_info.redir_stop = 0;
		g_info.fd_flag = 1;
		g_info.fd_storage[0] = dup(g_info.left_fd);
		start_pipe(tokens, head);
		return (1);
	}
	return (0);
}

void			both_exist(t_token **tokens, t_list **head)
{
	if (g_info.right_fd > 0)
	{
		g_info.fd_flag = 1;
		g_info.redir_stop = 1;
		g_info.fd_storage[0] = dup(g_info.left_fd);
		if (g_info.pipe_flag == 0)
		{
			g_info.pipe_flag = 2;
			start_pipe(tokens, head);
			ft_memset(g_info.buf, 0, 4096);
			read(g_info.fd_storage[0], g_info.buf, 4096);
			close(g_info.fd_storage[0]);
			write(g_info.right_fd, g_info.buf, ft_strlen(g_info.buf));
		}
		else
		{
			start_pipe(tokens, head);
			ft_memset(g_info.buf, 0, 4096);
			read(g_info.fd_storage[0], g_info.buf, 4096);
			close(g_info.fd_storage[0]);
			write(g_info.right_fd, g_info.buf, ft_strlen(g_info.buf));
		}
	}
}

void			exec_redir(t_token **tokens, t_list **head)
{
	init_redir_flag();
	if (loop_redir(tokens, 0))
		return ;
	if (!(*tokens)->token)
	{
		free((*tokens)->token);
		if (g_info.pipe_flag != 0)
			g_info.pipe_flag--;
		return ;
	}
	if (g_info.left_fd > 0)
	{
		if (g_info.right_fd > 0)
			both_exist(tokens, head);
		else
		{
			if (only_exist_left(tokens, head))
				return ;
		}
	}
	else if (g_info.right_fd > 0)
		only_exist_right(tokens, head);
	g_info.fd_flag = 0;
}
