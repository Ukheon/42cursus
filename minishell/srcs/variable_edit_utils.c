/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_edit_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:08:22 by hyeolee           #+#    #+#             */
/*   Updated: 2021/04/27 15:58:04 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int				check_invalid_variable(char *token, int idx, int *var_len)
{
	*var_len = 2;
	if (token[idx] >= '0' && token[idx] <= '9')
		return (1);
	if (is_space(token[idx]))
		return (1);
	return (0);
}

int				check_variable_area(char ch)
{
	if (ch == 0)
		return (0);
	else if (is_space(ch))
		return (0);
	else if (is_in_char(ch, "\"\'"))
		return (0);
	else if (!(ft_isalnum(ch)))
		return (0);
	return (1);
}

char			*except_variable(char ch)
{
	char		*temp;

	if (ch == '-')
		temp = ft_strdup("himBH");
	else if (ch == '$')
		temp = ft_itoa(g_info.save_pid);
	else
		temp = ft_itoa(g_info.error);
	return (temp);
}

int				variable_condition_check(char *token, int i, t_quote quote)
{
	if (token[i] != '$')
		return (0);
	else if (i - 1 >= 0 && token[i - 1] == '\\')
		return (0);
	else if (quote.quote == '\'')
		return (0);
	else if (!token[i + 1] || is_space(token[i + 1]))
		return (0);
	else if (is_in_char(token[i + 1], "-?$"))
		return (1);
	else if (!ft_isalnum(token[i + 1]))
		return (0);
	return (1);
}
