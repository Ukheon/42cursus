/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_edit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:06:47 by hyeolee           #+#    #+#             */
/*   Updated: 2021/05/02 15:26:47 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int				variable_edit(char *str, int idx, t_list **head, char **ret)
{
	char		*temp;
	int			var_len;

	var_len = 0;
	temp = change_to_constant(&str[idx], &var_len, head);
	*ret = join_str(*ret, temp);
	free(temp);
	return (var_len);
}

char			*change_to_constant(char *token, int *var_len, t_list **head)
{
	char		*temp;
	char		*value;
	int			idx;

	idx = 1;
	value = NULL;
	if (check_invalid_variable(token, idx, var_len))
		return (ft_strdup(""));
	if (is_in_char(token[idx], "-?$"))
	{
		value = except_variable(token[idx]);
		*var_len = 2;
		return (value);
	}
	while (check_variable_area(token[idx]))
		idx++;
	*var_len = idx;
	temp = ft_substr(token, 1, idx - 1);
	value = find_home(head, temp);
	if (value == NULL)
		value = ft_strdup("");
	free(temp);
	return (value);
}
