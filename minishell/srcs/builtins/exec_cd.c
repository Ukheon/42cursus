/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:49:28 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/01 12:00:04 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void			exec_home_exist(t_token **tokens, t_list **head)
{
	g_info.oldpwd = ft_strjoin("OLDPWD=", getcwd(g_info.buf, 4096));
	ft_memset(g_info.buf, 0, 4096);
	add_list(head, g_info.oldpwd, 0);
	free(g_info.oldpwd);
	if (chdir(g_info.address) == -1)
	{
		not_found_dir(tokens);
		free(g_info.address);
		return ;
	}
	if (getcwd(g_info.buf, 4096) != NULL)
	{
		change_pwd(head, g_info.buf);
		ft_memset(g_info.buf, 0, 4096);
	}
	free(g_info.address);
	return ;
}

int				exec_cd_home(t_token **tokens, t_list **head)
{
	g_info.idx = arr_row_check((*tokens)->argv);
	if (g_info.idx == 1)
	{
		g_info.address = find_home(head, "HOME");
		if (!g_info.address)
		{
			printf("$>: cd : HOME not set\n");
			g_info.error = 1;
			free(g_info.address);
			return (1);
		}
		exec_home_exist(tokens, head);
		return (1);
	}
	if (ft_strcmp((*tokens)->argv[1], "~") == 0)
	{
		if (!g_info.save_home)
			return (1);
		chdir(g_info.save_home);
		change_pwd(head, g_info.save_home);
		return (1);
	}
	return (0);
}

int				exec_cd_prev(t_token **tokens, t_list **head)
{
	g_info.address = ft_strdup((*tokens)->argv[1]);
	if (ft_strcmp(g_info.address, "-") == 0)
	{
		if (!find_in_env(head, "OLDPWD"))
		{
			oldpwd_not_set();
			return (1);
		}
		getcwd(g_info.buf, 4096);
		change_pwd(head, find_in_env(head, "OLDPWD"));
		chdir(find_in_env(head, "OLDPWD"));
		g_info.oldpwd = ft_strjoin("OLDPWD=", g_info.buf);
		ft_memset(g_info.buf, 0, 4096);
		getcwd(g_info.buf, 4096);
		printf("%s\n", g_info.buf);
		ft_memset(g_info.buf, 0, 4096);
		add_list(head, g_info.oldpwd, 0);
		free(g_info.oldpwd);
		free(g_info.address);
		return (1);
	}
	free(g_info.address);
	return (0);
}

int				exec_cd_folder(t_token **tokens, t_list **head)
{
	g_info.oldpwd = ft_strjoin("OLDPWD=", getcwd(g_info.buf, 4096));
	ft_memset(g_info.buf, 0, 4096);
	add_list(head, g_info.oldpwd, 0);
	free(g_info.oldpwd);
	g_info.address = ft_strdup((*tokens)->argv[1]);
	if (chdir(g_info.address) == -1)
	{
		g_info.error = 1;
		printf("$> %s: %s: No such file or directory\n",\
		(*tokens)->argv[0], (*tokens)->argv[1]);
		free(g_info.address);
		return (1);
	}
	if (getcwd(g_info.buf, 4096) != NULL)
	{
		change_pwd(head, g_info.buf);
		ft_memset(g_info.buf, 0, 4096);
	}
	free(g_info.address);
	return (0);
}

int				exec_cd(t_token **tokens, t_list **head)
{
	if (exec_cd_home(tokens, head))
		return (1);
	if (exec_cd_prev(tokens, head))
		return (1);
	if (exec_cd_folder(tokens, head))
		return (1);
	return (0);
}
