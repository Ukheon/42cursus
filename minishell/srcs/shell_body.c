/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:50:29 by ukwon             #+#    #+#             */
/*   Updated: 2021/06/17 20:21:42 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int				putchar_tc(int tc)
{
	write(1, &tc, 1);
	return (0);
}

void			working_token(t_token **tokens, t_list **head)
{
	t_token *temp;

	while (*tokens)
	{
		g_info.check++;
		g_info.enter_flag = 0;
		if ((*tokens)->redir_flag == 1)
			exec_redir(tokens, head);
		else if (!(*tokens)->token)
		{
			temp = (*tokens)->next;
			token_lstdelone(*tokens, free);
			*tokens = temp;
			continue ;
		}
		else if ((g_info.pipe_flag != 0 && (*tokens)->redir_flag == 0))
			start_pipe(tokens, head);
		else
			start_default(tokens, head);
		if (g_info.enter_flag == 1)
			free_split(g_info.env);
		temp = (*tokens)->next;
		token_lstdelone(*tokens, free);
		*tokens = temp;
	}
}

int				parse_minishell(char *line, t_list **head)
{
	t_token		*tokens;
	t_token		*temp;

	temp = NULL;
	tokens = NULL;
	if (check_syntax_error(line))
	{
		g_info.error = 258;
		return (0);
	}
	big_tokenizer(line, &tokens, head);
	get_cmdline(&tokens, head);
	working_token(&tokens, head);
	return (0);
}
