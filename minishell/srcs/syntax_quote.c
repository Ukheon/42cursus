/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:14:10 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/01 12:39:53 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void			backslash_check(char ch, t_quote *quote)
{
	if (ch != '\\')
		return ;
	else if (quote->quote == '\'')
	{
		quote->backslash = 0;
		return ;
	}
	else if (quote->backslash == 1)
	{
		quote->backslash = 0;
		return ;
	}
	else
		quote->backslash = 1;
}

int				double_quote_condition_check(char ch, t_quote *quote)
{
	if (ch != '\"')
		return (0);
	if (quote->backslash)
		return (0);
	if (quote->quote != ch)
		return (0);
	return (1);
}

void			quote_check(char ch, t_quote *quote)
{
	if (!is_in_char(ch, "\'\"\\"))
	{
		quote->backslash = 0;
		return ;
	}
	backslash_check(ch, quote);
	if (quote->quote == '\'' && ch == quote->quote)
	{
		quote->quote = 0;
		quote->quote_end = 1;
	}
	else if (double_quote_condition_check(ch, quote))
	{
		quote->quote = 0;
		quote->quote_end = 1;
	}
	else if (!quote->quote && quote->backslash == 0)
		quote->quote = ch;
}

void			quote_off_check(char ch, t_quote *quote)
{
	if ((quote->quote == '\'' && quote->quote == ch) || \
		(quote->quote == ch && quote->backslash == 0))
	{
		quote->quote = 0;
		quote->quote_end = 1;
	}
	quote->backslash = 0;
}

void			syntax_quote_check(char ch, t_quote *quote, int *i, char *str)
{
	if (!is_in_char(ch, "\'\"\\"))
	{
		quote->backslash = 0;
		return ;
	}
	if ((ch == '\\' && str[*i + 1] == '\\') || \
	(str[*i + 1] == '\"' && str[*i] != '\''))
	{
		(*i)++;
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
	if (quote->quote || (quote->backslash == 1 && ch == '\''))
		quote_off_check(ch, quote);
}
