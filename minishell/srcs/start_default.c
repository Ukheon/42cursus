/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:50:34 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/02 15:32:27 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void			change_pwd(t_list **head, char *str)
{
	t_list			*temp;

	temp = *head;
	while (temp)
	{
		if (ft_strcmp(temp->key, "PWD") == 0)
		{
			free(temp->value);
			temp->value = 0;
			temp->value = ft_strdup(str);
			return ;
		}
		temp = temp->next;
	}
}

void			exec_builtins(t_token **tokens, t_list **head)
{
	if ((ft_strcmp((*tokens)->cmd, "echo")) == 0)
		exec_echo(tokens, 0);
	else if ((ft_strcmp((*tokens)->cmd, "cd")) == 0)
	{
		if (exec_cd(tokens, head))
			return ;
	}
	else if (ft_strcmp((*tokens)->cmd, "unset") == 0)
		exec_unset(tokens, head);
	else if (ft_strcmp((*tokens)->cmd, "exit") == 0)
	{
		if (exec_exit(tokens, 1) == 1)
			return ;
		exit(g_info.error);
	}
	else if (ft_strcmp((*tokens)->cmd, "pwd") == 0)
		exec_pwd();
	else if (ft_strcmp((*tokens)->cmd, "export") == 0)
	{
		if (exec_export(tokens, head, 0))
			return ;
	}
	else if (ft_strcmp((*tokens)->cmd, "env") == 0)
		exec_env(tokens, head);
}

void			start_default(t_token **tokens, t_list **head)
{
	set_exec_data(head);
	if (is_valid_builtins(tokens))
		exec_builtins(tokens, head);
	else
		default_builtins(tokens, head);
}
