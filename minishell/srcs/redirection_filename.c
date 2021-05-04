/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_filename.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:13:15 by hyeolee           #+#    #+#             */
/*   Updated: 2021/04/24 19:14:44 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int				check_redir_filename(t_quote quote, char ch)
{
	if (!quote.quote && is_in_char(ch, "><"))
		return (1);
	else if (is_space(ch))
		return (1);
	return (0);
}

void			add_filename(t_list **redir, char *s, int len, t_token **token)
{
	(*redir)->next = 0;
	(*redir)->filename = ft_substr(s - len, 0, len);
	ft_lstadd_back(&(*token)->redir_list, *redir);
}
