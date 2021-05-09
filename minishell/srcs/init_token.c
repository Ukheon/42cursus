/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:11:20 by ukwon             #+#    #+#             */
/*   Updated: 2021/04/30 20:00:45 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void			quote_init(t_quote *quote)
{
	quote->quote = 0;
	quote->quote_end = 0;
	quote->backslash = 0;
}

void			option_init(t_options *option)
{
	option->word = -1;
	option->option = 0;
}

int				is_empty_string(char *str)
{
	if (!str)
		return (0);
	if (str[0])
		return (0);
	return (1);
}

t_token			*init_empty_token(t_token *token)
{
	free(token->token);
	token->token = 0;
	token = token->next;
	return (token);
}

void			init_tokenizer_flag(int *i, t_quote *quote)
{
	g_info.check = 0;
	g_info.fd_flag = 0;
	g_info.pipe_flag = 0;
	g_info.redir_flag = 0;
	g_info.redir_stop = 0;
	quote_init(quote);
	*i = 0;
}
