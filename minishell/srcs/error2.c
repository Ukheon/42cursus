/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:25:10 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/02 14:00:58 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void			not_valid_key(t_token **tokens, int i)
{
	char		*temp;

	temp = ft_substr((*tokens)->argv[g_info.idx], i + 1, \
	ft_strlen((*tokens)->argv[g_info.idx]));
	i = -1;
	while (temp[++i])
	{
		if (invalid_key_check(temp[i], i))
		{
			printf("$> : %s: `%s': not a valid identifier\n", \
			(*tokens)->cmd, (*tokens)->argv[g_info.idx]);
			break ;
		}
	}
	free(temp);
}

void			env_error_message(t_token **tokens)
{
	int			i;
	char		*temp;

	g_info.idx = -1;
	while ((*tokens)->argv[++g_info.idx])
	{
		i = -1;
		while ((*tokens)->argv[g_info.idx][++i])
		{
			if ((*tokens)->argv[g_info.idx][i] == '=')
				break ;
		}
		temp = ft_substr((*tokens)->argv[g_info.idx], 0, i + 1);
		if (check_valid_var(temp))
		{
			printf("$> : %s: `%s': not a valid identifier\n", \
			(*tokens)->cmd, (*tokens)->argv[g_info.idx]);
			free(temp);
			continue ;
		}
		free(temp);
		not_valid_key(tokens, i);
	}
}

void			pipe_export(t_token **tokens)
{
	g_info.idx = 0;
	while ((*tokens)->argv[++g_info.idx])
	{
		if (check_valid_var((*tokens)->argv[g_info.idx]))
			printf("$> : %s: `%s': not a valid identifier\n", \
			((*tokens)->cmd), (*tokens)->argv[g_info.idx]);
	}
}
