/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:17:11 by hyeolee           #+#    #+#             */
/*   Updated: 2021/04/30 17:21:05 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void			remove_quote_check(char ch, t_quote *quote)
{
	if (!is_in_char(ch, "\'\"\\"))
	{
		quote->backslash = 0;
		return ;
	}
	if (ch == '\\')
	{
		quote->backslash = 1;
		return ;
	}
	if (!quote->quote && quote->backslash == 0)
	{
		quote->quote = ch;
		return ;
	}
	if (quote->quote)
		quote_off_check(ch, quote);
}

int				edit_backslash(char *str, int *idx, t_quote quote, char **temp)
{
	if (quote.quote == '\'')
		return (0);
	if ((str[*idx + 1] != '\0' && str[*idx + 1] == '\"') || \
	((str[*idx + 1] == '\\' && quote.quote == '\"')) || str[*idx + 1] == '\'')
	{
		*temp = join_char(*temp, str[*idx + 1]);
		(*idx) += 1;
		return (1);
	}
	else if (str[*idx + 1] == ' ')
	{
		str[*idx] = -1;
		*temp = join_char(*temp, str[*idx]);
		(*idx) += 1;
		return (1);
	}
	else if (str[*idx + 1] == '\\' && quote.quote == 0)
	{
		*temp = join_char(*temp, str[*idx]);
		(*idx) += 1;
		return (1);
	}
	else if (!quote.quote && (*idx)++)
		return (1);
	return (0);
}

char			*loop_remove_quote(char *token)
{
	char		*temp;
	t_quote		quote;
	int			i;

	i = -1;
	quote_init(&quote);
	temp = ft_strdup("");
	while (token[++i])
	{
		remove_quote_check(token[i], &quote);
		if (quote.backslash == 1)
		{
			quote.backslash = 0;
			if (edit_backslash(token, &i, quote, &temp))
				continue ;
		}
		else if (quote.quote == token[i] || quote.quote_end)
		{
			quote.quote_end = 0;
			continue ;
		}
		temp = join_char(temp, token[i]);
	}
	return (temp);
}

char			*remove_quote(char *token)
{
	char		*temp;

	if (!token)
		return (0);
	temp = loop_remove_quote(token);
	free(token);
	return (temp);
}
