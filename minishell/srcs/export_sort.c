/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:20:05 by ukwon             #+#    #+#             */
/*   Updated: 2021/04/30 18:50:56 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void			exception_export(char *str)
{
	char			*key;
	char			*value;
	int				i;

	i = 0;
	while (str[i] != '=' && str[i] != 0)
		i++;
	key = ft_substr(str, 0, i);
	if ((int)ft_strlen(str) == i)
		printf("decalre -x %s\n", key);
	else if ((int)ft_strlen(str) == i + 1)
		printf("decalre -x %s=\"\"\n", key);
	else
	{
		value = ft_substr(str, i + 1, ft_strlen(str));
		free(value);
		printf("declare -x %s=\"%s\"\n", key, value);
	}
	free(key);
}

void			sort_row(char **s1, char **s2)
{
	char			*temp;

	if (ft_strcmp(*s1, *s2) >= 0)
	{
		temp = (*s1);
		(*s1) = (*s2);
		(*s2) = temp;
	}
}

void			sort_str(char **env)
{
	int		row;
	int		i;
	int		j;

	row = 0;
	while (env[row])
		row++;
	i = -1;
	while (++i < row)
	{
		j = 0;
		while (j < row - 1)
		{
			sort_row(&env[j], &env[j + 1]);
			j++;
		}
	}
	i = -1;
	while (++i < row)
		exception_export(env[i]);
}
