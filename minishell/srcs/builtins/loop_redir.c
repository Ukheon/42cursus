/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:49:51 by ukwon             #+#    #+#             */
/*   Updated: 2021/04/24 18:52:19 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int				check_left_redir(t_token **tokens, int fd)
{
	fd = open((*tokens)->redir_list->filename, O_RDONLY, 00777);
	if (fd < 0)
	{
		g_info.error = 1;
		if (g_info.pipe_flag != 0)
			g_info.pipe_flag--;
		printf("$> %s: No such file or directory\n", \
		(*tokens)->redir_list->filename);
		return (1);
	}
	g_info.left_fd = fd;
	return (0);
}

int				check_right_redir(t_token **tokens, int fd, char *redir)
{
	if (ft_strcmp(redir, ">") == 0)
	{
		fd = open((*tokens)->redir_list->filename, \
		O_WRONLY | O_CREAT | O_TRUNC, 00777);
		if (fd < 0)
		{
			printf("$> %s: No such file or directory\n", \
			(*tokens)->redir_list->filename);
			return (1);
		}
	}
	else
	{
		fd = open((*tokens)->redir_list->filename, \
		O_WRONLY | O_CREAT | O_APPEND, 00777);
		if (fd < 0)
		{
			printf("$> %s: No such file or directory\n", \
			(*tokens)->redir_list->filename);
			return (1);
		}
	}
	g_info.right_fd = fd;
	return (0);
}

int				loop_redir(t_token **tokens, int fd)
{
	t_list	*temp;

	while ((*tokens)->redir_list)
	{
		if (ft_strcmp((*tokens)->redir_list->redir, ">") == 0 || \
		ft_strcmp((*tokens)->redir_list->redir, ">>") == 0)
		{
			if (check_right_redir(tokens, fd, (*tokens)->redir_list->redir))
				return (1);
		}
		else if (ft_strcmp((*tokens)->redir_list->redir, "<") == 0)
		{
			if (check_left_redir(tokens, fd))
				return (1);
		}
		temp = (*tokens)->redir_list->next;
		free((*tokens)->redir_list->filename);
		free((*tokens)->redir_list->redir);
		free((*tokens)->redir_list);
		(*tokens)->redir_list = temp;
	}
	return (0);
}
