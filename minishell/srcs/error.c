/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:50:13 by ukwon             #+#    #+#             */
/*   Updated: 2021/04/30 17:13:00 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int				quote_error_check(char *line)
{
	int			i;
	t_quote		quote;

	i = 0;
	quote_init(&quote);
	while (line[i])
	{
		syntax_quote_check(line[i], &quote, &i, line);
		i++;
	}
	if (quote.quote)
		return (1);
	return (0);
}

int				option_error_check(char *line)
{
	t_options	option;
	t_quote		quote;

	option_init(&option);
	quote_init(&quote);
	while (*line)
	{
		quote_check(*line, &quote);
		if (!is_space(*line) && !is_in_char(*line, ";|"))
			option.word = 1;
		if (is_in_char(*line, ";|"))
		{
			if (option.word == -1)
				return (1);
			else if (!quote.quote)
			{
				option.option = *line;
				option.word = -1;
			}
		}
		line++;
	}
	return (0);
}

int				right_redir_error_check(char *line)
{
	int			i;
	int			continued_redir;
	t_quote		quote;

	quote_init(&quote);
	continued_redir = 0;
	i = 0;
	while (line[i])
	{
		quote_check(line[i], &quote);
		if (!quote.quote && line[i] == '>')
			continued_redir++;
		else if (!is_space(line[i]))
			continued_redir = 0;
		if (continued_redir > 2)
			return (1);
		i++;
	}
	return (0);
}

int				left_redir_error_check(char *line)
{
	int			i;
	int			continued_redir;
	t_quote		quote;

	quote_init(&quote);
	continued_redir = 0;
	i = 0;
	while (line[i])
	{
		quote_check(line[i], &quote);
		if (!quote.quote && line[i] == '<')
			continued_redir++;
		else if (!is_space(line[i]))
			continued_redir = 0;
		if (continued_redir > 1)
			return (1);
		i++;
	}
	return (0);
}

int				new_line_error_check(char *line)
{
	int			i;
	int			check;
	t_quote		quote;

	i = 0;
	check = 0;
	quote_init(&quote);
	while (line[i])
	{
		quote_check(line[i], &quote);
		if (!quote.quote && is_in_char(line[i], "><|(){}!"))
			check = 1;
		else if (!is_space(line[i]))
			check = 0;
		i++;
	}
	return (check);
}
