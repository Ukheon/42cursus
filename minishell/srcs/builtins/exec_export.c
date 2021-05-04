/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:49:44 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/02 14:25:06 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int				exec_export(t_token **tokens, t_list **head, int num)
{
	g_info.idx = arr_row_check((*tokens)->argv);
	if (g_info.idx == 1)
	{
		sort_str(g_info.env);
		return (1);
	}
	g_info.idx = 0;
	if (num != 10)
		export_add_list(tokens, head, num);
	return (0);
}

void			equal_exist(t_list **head, char *str, int save, int num)
{
	char	*temp;
	char	*value;

	temp = ft_substr(str, 0, save);
	if (check_valid_var(temp))
	{
		printf("$> : export: `%s': not a valid identifier\n", str);
		free(temp);
		if (num == 0)
			return ;
		exit(3);
	}
	if (!(find_in_env(head, temp)))
		ft_lstadd_back(head, ft_lstnew(str));
	else
	{
		if ((int)ft_strlen(str) == save)
			change_value(head, temp, 0, NULL);
		else
		{
			value = ft_substr(str, save + 1, ft_strlen(str));
			change_value(head, temp, 1, value);
		}
	}
	free(temp);
}

int				export_error(char *str, int num)
{
	int		i;
	int		save;
	int		flag;
	char	*temp;

	flag = 0;
	save = 0;
	i = -1;
	while (str[++i])
	{
		if (invalid_key_check(str[i], flag))
		{
			temp = ft_substr(str, 0, ft_strlen(str));
			printf("$> : export: `%s': not a valid identifier\n", temp);
			free(temp);
			if (num == 0)
				return (-1);
			exit(3);
		}
		if (str[i] == '=' && save == 0)
			save = i;
		flag = 1;
	}
	i = -1;
	return (save);
}

void			export_not_equal(t_list **head, \
char *str, int num)
{
	char	*temp;

	temp = ft_strdup(str);
	if (check_valid_var(temp))
	{
		printf("$> : export: `%s': not a valid identifier\n", str);
		free(temp);
		if (num == 0)
			return ;
		exit(3);
	}
	if (!(find_in_env(head, temp)))
		ft_lstadd_back(head, ft_lstnew(str));
	free(temp);
}

void			export_list(t_list **head, char *str, int num)
{
	int		save;

	g_info.error = 1;
	save = export_error(str, num);
	if (save < 0)
		return ;
	if (export_valid_check(head, str, save, num))
	{
		if (num == 0)
			return ;
		exit(2);
	}
	if (save == 0)
		export_not_equal(head, str, num);
	g_info.error = 0;
}
