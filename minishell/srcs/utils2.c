/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:50:44 by ukwon             #+#    #+#             */
/*   Updated: 2021/05/17 16:21:35 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void			change_value(t_list **head, char *str, int flag, char *value)
{
	t_list		*temp;


	temp = *head;
	while (temp)
	{
		if (ft_strncmp(temp->key, str, ft_strlen(str)) == 0 && flag == 0)
		{
			free(temp->value);
			temp->value = ft_strdup("");
			return ;
		}
		else if (ft_strncmp(temp->key, str, ft_strlen(str)) == 0 && flag == 1)
		{
			temp->flag = 1;
			free(temp->value);
			temp->value = ft_strdup(value);
			free(value);
			return ;
		}
		temp = temp->next;
	}
	free(value);
}

int				check_valid_var(char *temp)
{
	int			i;

	i = 0;
	while (temp[i])
	{
		if ((temp[0] >= '0' && temp[0] <= '9') || (temp[i] >= 33 && \
		temp[i] <= 47) || (temp[i] >= 58 && temp[i] <= 64) \
		|| (temp[i] >= 91 && temp[i] <= 94) || temp[i] == 96 || temp[i] == ' ')
		{
			g_info.error = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

char			**fill_env_data(t_list **head)
{
	t_list		*temp;
	int			idx;
	char		*str;
	char		*str_temp;
	char		**env;

	idx = 0;
	temp = *head;
	env = (char **)malloc(sizeof(char *) * (ft_lstsize(*head) + 1));
	env[ft_lstsize(*head)] = NULL;
	while (temp)
	{
		if (temp->flag == 1)
			str_temp = ft_strjoin(temp->key, "=");
		else
			str_temp = ft_strdup(temp->key);
		str = ft_strjoin(str_temp, temp->value);
		if (str_temp)
			free(str_temp);
		env[idx++] = ft_strdup(str);
		if (str)
			free(str);
		temp = temp->next;
	}
	return (env);
}

char			*find_home(t_list **head, char *str)
{
	t_list		*temp;

	temp = *head;
	while (temp)
	{
		if (ft_strcmp(temp->key, str) == 0)
		{
			if (!temp->value)
				return (NULL);
			return (ft_strdup(temp->value));
		}
		temp = temp->next;
	}
	return (NULL);
}

char			*find_in_env(t_list **head, char *str)
{
	t_list		*temp;

	temp = *head;
	while (temp)
	{
		if (ft_strcmp(temp->key, str) == 0)
		{
			if (!temp->value)
				return (NULL);
			return (temp->value);
		}
		temp = temp->next;
	}
	return (NULL);
}
