/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:47:30 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/02 14:20:51 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int				export_valid_check(t_list **head, char *str, int save, int num)
{
	int		i;

	g_info.error = 0;
	i = -1;
	while (str[++i])
	{
		if (str[0] != '=' && str[i] == '=')
		{
			equal_exist(head, str, save, num);
			return (1);
		}
	}
	return (0);
}

int				invalid_key_check(char ch, int flag)
{
	if ((flag == 0 && ch == '=') || (flag == 0 && ch >= '0' && ch <= '9') \
	|| ch == ' ')
		return (1);
	return (0);
}

int				is_valid_builtins(t_token **tokens)
{
	if ((ft_strcmp((*tokens)->cmd, "echo")) == 0 ||
	(ft_strcmp((*tokens)->cmd, "cd") == 0) ||
	(ft_strcmp((*tokens)->cmd, "unset") == 0) ||
	(ft_strcmp((*tokens)->cmd, "exit") == 0) ||
	(ft_strcmp((*tokens)->cmd, "pwd") == 0) ||
	(ft_strcmp((*tokens)->cmd, "export") == 0) ||
	(ft_strcmp((*tokens)->cmd, "env") == 0))
		return (1);
	return (0);
}
