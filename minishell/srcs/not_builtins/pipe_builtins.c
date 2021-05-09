/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:50:04 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/02 18:32:37 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void			pipe_parent(t_token **tokens)
{
	if (g_info.status == 256)
		g_info.error = 1;
	else if (g_info.status == 768)
	{
		printf("$> %s: command not found\n", (*tokens)->cmd);
		g_info.error = 1;
	}
	else if (g_info.status == 1024)
	{
		printf("$> %s: command not found\n", (*tokens)->cmd);
		g_info.error = 127;
	}
	else if (g_info.status == 1280)
	{
		printf("$> ls: command not found\n");
		g_info.error = 1;
	}
	else if (g_info.status == 1536)
		g_info.error = g_info.status % 255;
	if (g_info.check2 == 1)
		g_info.error = 131;
}

void			failed_execve(t_token **tokens, t_list **head)
{
	free(g_info.path_str);
	free(g_info.cmd);
	g_info.cmd = ft_strtrim((*tokens)->cmd, ".");
	g_info.cmd = ft_strjoin("/", g_info.cmd);
	g_info.path_str = find_in_env(head, "PWD");
	execve(ft_strjoin(g_info.path_str, g_info.cmd), \
	(*tokens)->argv, g_info.env);
	execve((*tokens)->cmd, (*tokens)->argv, g_info.env);
	printf("$>: %s: command not found\n", (*tokens)->cmd);
	exit(0);
}

void			pipe_child(t_token **tokens, t_list **head)
{
	if (g_info.path_str)
	{
		g_info.split = ft_split(g_info.path_str, ':');
		g_info.idx = 0;
		g_info.cmd = ft_strjoin("/", (*tokens)->cmd);
		while (g_info.split[g_info.idx])
		{
			execve(ft_strjoin(g_info.split[g_info.idx], \
			g_info.cmd), (*tokens)->argv, g_info.env);
			g_info.idx++;
		}
		failed_execve(tokens, head);
	}
	else if (ft_strcmp((*tokens)->cmd, "ls") == 0)
		printf("$>: ls: No such file or directory\n");
	else
		printf("$>: %s: command not found\n", (*tokens)->cmd);
	exit(0);
}

void			pipe_builtins(t_token **tokens, t_list **head)
{
	g_info.signal_flag = 1;
	pipe(g_info.fds);
	g_info.pid = fork();
	g_info.path_str = find_in_env(head, "PATH");
	if (g_info.pid == 0)
	{
		ft_memset(g_info.buf, 0, 4096);
		read(g_info.fd_storage[0], g_info.buf, 4096);
		close(g_info.fd_storage[0]);
		write(g_info.fds[1], g_info.buf, ft_strlen(g_info.buf));
		dup2(g_info.fds[0], 0);
		close(g_info.fds[1]);
		pipe_child(tokens, head);
	}
	else
	{
		close(g_info.fds[1]);
		close(g_info.fds[0]);
		wait(&g_info.status);
		pipe_parent(tokens);
	}
}
