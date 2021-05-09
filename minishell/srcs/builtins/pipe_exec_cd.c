/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec_cd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:49:59 by ukwon             #+#    #+#             */
/*   Updated: 2021/04/30 17:52:23 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void			not_found_dir(t_token **tokens)
{
	g_info.error = 1;
	printf("$> %s: %s: No such file or directory\n",\
	(*tokens)->argv[0], (*tokens)->argv[1]);
	free(g_info.address);
}

void			oldpwd_not_set(void)
{
	free(g_info.address);
	printf("$>: cd: OLDPWD not set\n");
	g_info.error = 1;
}

int				pipe_cd_folder(t_token **tokens, t_list **head)
{
	g_info.pid = fork();
	if (g_info.pid == 0)
	{
		g_info.oldpwd = ft_strjoin("OLDPWD=", getcwd(g_info.buf, 4096));
		ft_memset(g_info.buf, 0, 4096);
		add_list(head, g_info.oldpwd, 0);
		free(g_info.oldpwd);
		if (chdir(g_info.address) == -1)
		{
			not_found_dir(tokens);
			exit(1);
		}
		if (getcwd(g_info.buf, 4096) != NULL)
		{
			change_pwd(head, g_info.buf);
			ft_memset(g_info.buf, 0, 4096);
		}
		free(g_info.address);
		exit(0);
	}
	wait(&g_info.status);
	free(g_info.address);
	if (g_info.status == 256)
		g_info.error = 1;
	return (0);
}

int				pipe_exec_cd(t_token **tokens, t_list **head)
{
	g_info.idx = arr_row_check((*tokens)->argv);
	if (g_info.idx == 1)
	{
		g_info.address = find_home(head, "HOME");
		if (!g_info.address)
		{
			printf("$>: cd : HOME not set\n");
			g_info.error = 1;
		}
		free(g_info.address);
		return (0);
	}
	g_info.address = ft_strdup((*tokens)->argv[1]);
	if (ft_strcmp(g_info.address, "-") == 0)
	{
		if (!find_in_env(head, "OLDPWD"))
			oldpwd_not_set();
		return (0);
	}
	g_info.error = 0;
	pipe_cd_folder(tokens, head);
	return (0);
}
