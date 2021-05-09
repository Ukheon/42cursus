/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:50:01 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/02 18:31:18 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void			default_parent(t_token **tokens)
{
	wait(&g_info.status);
	g_info.error = g_info.status / 256;
	if (g_info.error == 0)
	{
		if ((ft_strcmp((*tokens)->cmd, "cat") == 0) ||
		(ft_strcmp((*tokens)->cmd, "grep") == 0))
			g_info.error = 130;
		if ((ft_strcmp((*tokens)->cmd, "/bin/cat") == 0 || \
		(ft_strcmp((*tokens)->cmd, "/usr/bin/grep") == 0)))
			g_info.error = 130;
	}
	if (g_info.check2 == 1)
		g_info.error = 131;
}

void			default_child(t_token **tokens, t_list **head)
{
	g_info.path_str = find_in_env(head, "PATH");
	if (g_info.path_str)
	{
		g_info.split = ft_split(g_info.path_str, ':');
		g_info.cmd = ft_strjoin("/", (*tokens)->cmd);
		g_info.idx = 0;
		while (g_info.split[g_info.idx])
		{
			execve(ft_strjoin(g_info.split[g_info.idx], \
			g_info.cmd), (*tokens)->argv, g_info.env);
			g_info.idx++;
		}
		free(g_info.path_str);
		free(g_info.cmd);
		g_info.cmd = ft_strtrim((*tokens)->cmd, ".");
		g_info.cmd = ft_strjoin("/", g_info.cmd);
		g_info.path_str = find_in_env(head, "PWD");
		execve(ft_strjoin(g_info.path_str, g_info.cmd), \
		(*tokens)->argv, g_info.env);
		execve((*tokens)->cmd, (*tokens)->argv, g_info.env);
		printf("$> %s: command not found\n", (*tokens)->cmd);
		exit(127);
	}
	printf("$> %s: No such file or directory\n", ((*tokens)->cmd));
	exit(127);
}

int				default_builtins(t_token **tokens, t_list **head)
{
	g_info.signal_flag = 1;
	g_info.pid = fork();
	if (g_info.pid == 0)
		default_child(tokens, head);
	else
		default_parent(tokens);
	return (0);
}
