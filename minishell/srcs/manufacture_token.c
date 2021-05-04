/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manufacture_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:51:54 by hyeolee           #+#    #+#             */
/*   Updated: 2021/05/01 12:39:02 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char			*manufacture_token(char *token, t_list **head)
{
	char		*ret;
	t_quote		quote;
	int			i;
	int			var_len;

	i = 0;
	ret = 0;
	quote_init(&quote);
	while (token[i])
	{
		quote_check(token[i], &quote);
		var_len = 0;
		if (variable_condition_check(token, i, quote))
			var_len = variable_edit(token, i, head, &ret);
		else
		{
			if (quote.quote && is_space(token[i]))
				token[i] = -1;
			ret = join_char(ret, token[i]);
			var_len = 1;
		}
		i += var_len;
	}
	return (ret);
}

void			manufacture_cmdline(t_token **tokens, t_list **head)
{
	t_token		*temp;
	char		*tmp_str;

	temp = *tokens;
	while (temp)
	{
		tmp_str = manufacture_token(temp->token, head);
		free(temp->token);
		temp->token = ft_strdup(tmp_str);
		free(tmp_str);
		temp = temp->next;
	}
}
