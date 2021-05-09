/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_last_builtins.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:50:06 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/01 12:32:14 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void			not_found(t_token **tokens, t_list **head)
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

void			pipe_last_child(t_token **tokens, t_list **head)
{
	dup2(g_info.fd_storage[0], 0);
	close(g_info.fds[1]);
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
		not_found(tokens, head);
	}
	else if (ft_strcmp((*tokens)->cmd, "ls") == 0)
		printf("$>: ls: No such file or directory\n");
	else
		printf("$>: %s: command not found\n", (*tokens)->cmd);
	exit(0);
}

void			pipe_last_builtins(t_token **tokens, t_list **head)
{
	g_info.signal_flag = 1;
	pipe(g_info.fds);
	g_info.pid = fork();
	g_info.path_str = find_in_env(head, "PATH");
	if (g_info.pid == 0)
		pipe_last_child(tokens, head);
	else
	{
		close(g_info.fds[1]);
		close(g_info.fds[0]);
		wait(&g_info.status);
		pipe_parent(tokens);
	}
}
