/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:50:38 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/02 15:31:19 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void			not_builtins_pipe(t_token **tokens, t_list **head)
{
	g_info.path_str = find_in_env(head, "PATH");
	if (g_info.path_str)
	{
		g_info.split = ft_split(g_info.path_str, ':');
		g_info.idx = 0;
		g_info.cmd = ft_strjoin("/", (*tokens)->cmd);
		while (g_info.split[g_info.idx])
		{
			execve(ft_strjoin(g_info.split[g_info.idx], g_info.cmd), \
			(*tokens)->argv, g_info.env);
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
		exit(3);
	}
}

void			parsing_child(t_token **tokens, t_list **head)
{
	set_child_dup();
	if (ft_strcmp((*tokens)->cmd, "echo") == 0)
		exec_echo(tokens, 0);
	else if (ft_strcmp((*tokens)->cmd, "cd") == 0)
		exit(3);
	else if (ft_strcmp((*tokens)->cmd, "unset") == 0)
		pipe_exec_unset(tokens, head, 0);
	else if (ft_strcmp((*tokens)->cmd, "exit") == 0)
	{
		if (exec_exit(tokens, 0))
			exit(3);
		exit(g_info.error);
	}
	else if (ft_strcmp((*tokens)->cmd, "pwd") == 0)
		exec_pwd();
	else if (ft_strcmp((*tokens)->cmd, "export") == 0)
		exec_export(tokens, head, 1);
	else if (ft_strcmp((*tokens)->cmd, "env") == 0)
		exec_env(tokens, head);
	else
		not_builtins_pipe(tokens, head);
	exit(0);
}

void			parsing_parent(t_token **tokens, t_list **head)
{
	if (g_info.status == 768)
	{
		if (ft_strcmp((*tokens)->cmd, "unset") == 0 || \
		ft_strcmp((*tokens)->cmd, "export") == 0)
			env_error_message(tokens);
		else if (ft_strcmp((*tokens)->cmd, "cd") == 0)
			pipe_exec_cd(tokens, head);
		else if (ft_strcmp((*tokens)->cmd, "exit") == 0)
		{
			if (!numeric_error_check(tokens, 1))
				many_argv_check(tokens, 1);
		}
		else
		{
			printf("$> %s: command not found\n", (*tokens)->cmd);
			g_info.error = 1;
		}
	}
}

void			get_execve_data(t_token **tokens, t_list **head)
{
	g_info.fd_flag = 0;
	if (ft_strcmp((*tokens)->cmd, "echo") == 0)
		exec_echo(tokens, 0);
	else if (ft_strcmp((*tokens)->cmd, "exit") == 0)
	{
		if (!numeric_error_check(tokens, 1))
			if (!many_argv_check(tokens, 1))
				if (arr_row_check((*tokens)->argv) != 1)
					g_info.error = ft_atoi((*tokens)->argv[1]) % 256;
	}
	else if (ft_strcmp((*tokens)->cmd, "cd") == 0)
		pipe_exec_cd(tokens, head);
	else if (ft_strcmp((*tokens)->cmd, "unset") == 0)
		pipe_exec_unset(tokens, head, 1);
	else if (ft_strcmp((*tokens)->cmd, "pwd") == 0)
		exec_pwd();
	else if (ft_strcmp((*tokens)->cmd, "export") == 0)
		pipe_export(tokens);
	else if (ft_strcmp((*tokens)->cmd, "env") == 0)
		exec_env(tokens, head);
	else if (g_info.redir_stop == 0)
		pipe_last_builtins(tokens, head);
}

void			start_pipe(t_token **tokens, t_list **head)
{
	set_pipe(head);
	if (g_info.pipe_flag >= 1)
	{
		set_fd();
		g_info.pid = fork();
		if (g_info.pid == 0)
			parsing_child(tokens, head);
		else
		{
			parent_wait();
			parsing_parent(tokens, head);
		}
		g_info.fd_flag = 1;
		g_info.fd_storage[0] = dup(g_info.dfs[0]);
		close(g_info.dfs[0]);
	}
	else
		get_execve_data(tokens, head);
	g_info.redir_stop = 0;
}
