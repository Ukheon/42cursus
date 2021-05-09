/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:12:38 by ukheon            #+#    #+#             */
/*   Updated: 2021/03/03 03:38:25 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int		insert_line(char **board, char **line, int index)
{
	char	*save;

	if (index >= 0)
	{
		(*board)[index] = '\0';
		if (!(*line = ft_strdup(*board)))
			return (_ERROR);
		save = ft_strdup(*board + index + 1);
		free(*board);
		*board = save;
		return (_NOTEND);
	}
	else
	{
		if (!(*line = ft_strdup(*board)))
			return (_ERROR);
		free(*board);
		*board = NULL;
		return (_ENDFILE);
	}
	return (_ERROR);
}

static int		check_board(char *board)
{
	int					i;

	i = 0;
	while (board[i])
	{
		if (board[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	static char			*board[1];
	char				*buf;
	char				*str;
	ssize_t				r_size;
	int					index;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (_ERROR);
	if (!board[fd])
		board[fd] = ft_strdup("");
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	while ((index = check_board(board[fd])) < 0 && \
			(r_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[r_size] = '\0';
		str = ft_strjoin(board[fd], buf);
		if (board[fd])
			free(board[fd]);
		board[fd] = str;
	}
	free(buf);
	if (r_size < 0)
		return (_ERROR);
	return (insert_line(&board[fd], line, index));
}
