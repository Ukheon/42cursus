/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 21:05:32 by ukwon             #+#    #+#             */
/*   Updated: 2021/04/30 18:50:30 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*get_list_data(t_list *new, char *str, int save)
{
	if (!new)
		return (0);
	if (save == 0)
		new->flag = 0;
	else
		new->flag = 1;
	if (save == 0)
		new->key = ft_substr(str, 0, (int)ft_strlen(str));
	else
		new->key = ft_substr(str, 0, save);
	if ((int)ft_strlen(str) == save)
		new->value = ft_strdup("");
	else if (save != 0)
		new->value = ft_substr(str, save + 1, ft_strlen(str));
	else
		new->value = ft_strdup("");
	new->redir = NULL;
	new->filename = NULL;
	new->next = 0;
	return (new);
}

t_list			*ft_lstnew(char *str)
{
	t_list	*new;
	int		i;
	int		save;

	if (!str)
		return (0);
	save = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '=' && save == 0)
		{
			save = i;
			break ;
		}
	}
	new = (t_list *)malloc(sizeof(t_list));
	new = get_list_data(new, str, save);
	return (new);
}
