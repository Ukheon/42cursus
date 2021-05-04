/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:50:20 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/01 12:26:22 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void			init_term(void)
{
	tcgetattr(STDIN_FILENO, &g_info.default_term);
	tcgetattr(STDIN_FILENO, &g_info.term);
	g_info.error = 0;
	g_info.term.c_lflag &= ~ICANON;
	g_info.term.c_lflag &= ~ECHO;
	g_info.term.c_cc[VMIN] = 1;
	g_info.term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &g_info.term);
	tgetent(NULL, "xterm");
	g_info.cm = tgetstr("cm", NULL);
	g_info.ce = tgetstr("ce", NULL);
	g_info.pid = fork();
	if (g_info.pid == 0)
		exit(0);
	else
	{
		g_info.save_pid = g_info.pid - 1;
		wait(&g_info.status);
	}
}

void			init_info(int num)
{
	if (num == 0)
	{
		ft_memset(g_info.buf, 0, 4096);
		g_info.c = 0;
		g_info.idx = 0;
		g_info.c = 0;
		g_info.his_idx = 0;
		g_info.history_flag = 0;
		g_info.write_flag = 0;
		g_info.first_flag = 0;
		g_info.signal_flag = 0;
		g_info.status = 0;
	}
}

void			init_redir_flag(void)
{
	g_info.redir_flag = 0;
	g_info.left_fd = 0;
	g_info.right_fd = 0;
	g_info.redir_stop = 1;
}

void			init_list(t_list **head, char *envp[])
{
	int					i;

	i = 0;
	while (envp[i])
	{
		ft_lstadd_back(head, ft_lstnew(envp[i]));
		i++;
	}
	g_info.save_home = find_home(head, "HOME");
	unset_list(head, "OLDPWD");
}

void			init_tokens(t_token **tokens)
{
	t_token				*temp;

	temp = *tokens;
	while (temp)
	{
		temp->argv = 0;
		temp->cmd = 0;
		temp = temp->next;
	}
}
