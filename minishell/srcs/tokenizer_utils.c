/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:43:18 by hyeolee           #+#    #+#             */
/*   Updated: 2021/05/01 12:33:54 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int				is_seperate_token(char *line, int i)
{
	if (!line[i + 1])
		return (1);
	return (0);
}

void			recursive_semi(char **str, t_list **head, char *line, int *idx)
{
	*str = ft_substr((line), 0, *idx);
	parse_minishell(*str, head);
	free(*str);
	(*idx)++;
	*str = ft_substr(line + *idx, 0, ft_strlen(line + *idx));
	parse_minishell(*str, head);
	free(*str);
}

void			seperate_token(char **str, char *line, int *idx)
{
	*str = ft_substr(line, 0, ft_strlen(line) + 1);
	*idx = -1;
	while ((*str)[++(*idx)])
	{
		if (is_in_char((*str)[(*idx)], "|"))
		{
			if (g_info.pipe_flag == 0)
				g_info.pipe_flag += 2;
			else
				g_info.pipe_flag++;
		}
	}
	*idx = ft_strlen((*str)) - 1;
	while (*idx >= 0)
	{
		if (!is_space((*str)[*idx]))
			break ;
		(*idx)--;
	}
}

void			add_token(char **str, t_token **tokens, int *idx)
{
	g_info.split = ft_split(*str, '|');
	*idx = -1;
	while (g_info.split[++(*idx)])
	{
		change_to_space(g_info.split[*idx]);
		token_add_back(tokens, new_token(g_info.split[*idx]));
		if (g_info.pipe_flag == 0)
			break ;
	}
	free(*str);
	free_split(g_info.split);
}
