/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:39:35 by hyeolee           #+#    #+#             */
/*   Updated: 2021/05/01 12:33:58 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void			big_tokenizer(char *line, t_token **tokens, t_list **head)
{
	int			i;
	t_quote		quote;
	char		*temp;

	init_tokenizer_flag(&i, &quote);
	while (is_space(line[i]))
		i++;
	while (line[i])
	{
		quote_check(line[i], &quote);
		if (!quote.quote && is_in_char(line[i], ";"))
		{
			recursive_semi(&temp, head, line, &i);
			return ;
		}
		if (quote.quote && is_in_char(line[i], "|"))
			line[i] = -2;
		else if (is_seperate_token(line, i))
		{
			seperate_token(&temp, line, &i);
			add_token(&temp, tokens, &i);
			return ;
		}
		i++;
	}
}
