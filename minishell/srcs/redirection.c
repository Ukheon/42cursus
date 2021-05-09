/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:56:00 by hyeolee           #+#    #+#             */
/*   Updated: 2021/05/01 12:35:56 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int				add_redir_list(t_token **temp, char *str)
{
	int			i;
	int			start_idx;
	t_quote		quote;
	t_list		*redir;

	if (!str)
		return (0);
	redir = (t_list *)malloc(sizeof(t_list) * 1);
	i = 0;
	quote_init(&quote);
	while (is_in_char(str[i], "><"))
		i++;
	redir->redir = ft_substr(str, 0, i);
	while (is_space(str[i]) && str[i])
		i++;
	start_idx = i;
	while (str[i])
	{
		quote_check(str[i], &quote);
		if (check_redir_filename(quote, str[i]))
			break ;
		i++;
	}
	add_filename(&redir, &str[i], i - start_idx, temp);
	return (i);
}

char			*redir_modify_token(char *str, t_var parser)
{
	char		*temp;
	int			str_len;
	int			i;
	int			j;

	j = 0;
	i = 0;
	str_len = ft_strlen(str);
	str_len -= parser.redir_len;
	temp = (char *)malloc(sizeof(char) * str_len + 1);
	while (str[i])
	{
		if (i >= parser.start_idx && i <= parser.end_idx)
		{
			i++;
			continue ;
		}
		temp[j++] = str[i];
		i++;
	}
	temp[j] = '\0';
	return (temp);
}

void			retry_seperate_redir(t_token **token, int flag, char *tmp_str)
{
	if (!ft_strlen((*token)->token))
	{
		free((*token)->token);
		(*token)->token = NULL;
		if (flag == 1)
			(*token)->redir_flag = 1;
	}
	else if (flag)
	{
		(*token)->redir_flag = 1;
		free((*token)->token);
		(*token)->token = ft_strdup(tmp_str);
		free(tmp_str);
		seperate_redir(token);
	}
}

void			seperate_redir(t_token **token)
{
	int			i;
	char		*tmp_str;
	t_quote		quote;
	t_var		parser;
	int			flag;

	tmp_str = NULL;
	flag = 0;
	i = -1;
	quote_init(&quote);
	parser_init(&parser);
	while ((*token)->token[++i])
	{
		quote_check((*token)->token[i], &quote);
		if (!quote.quote && is_in_char((*token)->token[i], "><"))
		{
			flag = 1;
			parser.start_idx = i;
			parser.redir_len = add_redir_list(token, &(*token)->token[i]);
			parser.end_idx = parser.start_idx + parser.redir_len - 1;
			tmp_str = redir_modify_token((*token)->token, parser);
			break ;
		}
	}
	retry_seperate_redir(token, flag, tmp_str);
}

void			manufacture_redir_filename(t_list **redir_list)
{
	t_list		*tmp_list;
	char		*tmp_str;
	int			i;

	if (*redir_list)
		return ;
	i = 0;
	tmp_list = *redir_list;
	while (tmp_list)
	{
		tmp_str = remove_quote(tmp_list->filename);
		tmp_list->filename = ft_strdup(tmp_str);
		change_to_space(tmp_list->filename);
		free(tmp_str);
		tmp_list = tmp_list->next;
	}
}
