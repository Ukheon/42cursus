/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmdline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:46:04 by hyeolee           #+#    #+#             */
/*   Updated: 2021/05/01 12:39:35 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void			seperate_cmd(t_token **tokens)
{
	t_token		*temp;

	temp = *tokens;
	while (temp)
	{
		temp->redir_list = NULL;
		temp->redir_flag = 0;
		if (is_empty_string(temp->token))
		{
			temp = init_empty_token(temp);
			continue ;
		}
		temp->redir_flag = 0;
		seperate_redir(&temp);
		if (temp->redir_list)
			temp->redir_flag = 1;
		if (temp->redir_flag == 1)
			manufacture_redir_filename(&temp->redir_list);
		seperate_cmdline(&temp);
		temp = temp->next;
	}
}

void			erase_blank(t_token **tokens)
{
	char		*temp;
	t_token		*tmp_token;

	tmp_token = (*tokens);
	while (tmp_token)
	{
		temp = ft_strtrim(tmp_token->token, " ");
		free(tmp_token->token);
		tmp_token->token = ft_strdup(temp);
		free(temp);
		tmp_token = tmp_token->next;
	}
}

void			seperate_cmdline(t_token **token)
{
	int			i;

	if (is_empty_string((*token)->token))
	{
		free((*token)->token);
		(*token)->token = NULL;
	}
	if ((*token)->token == NULL)
		return ;
	(*token)->argv = ft_split((*token)->token, ' ');
	i = 0;
	while ((*token)->argv[i])
	{
		(*token)->argv[i] = remove_quote((*token)->argv[i]);
		change_to_space((*token)->argv[i]);
		i++;
	}
	(*token)->cmd = ft_strdup((*token)->argv[0]);
}

void			get_cmdline(t_token **tokens, t_list **head)
{
	init_tokens(tokens);
	erase_blank(tokens);
	manufacture_cmdline(tokens, head);
	seperate_cmd(tokens);
}
