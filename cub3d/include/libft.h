/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 03:40:50 by ukwon             #+#    #+#             */
/*   Updated: 2021/02/18 15:41:36 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

int				ft_atoi(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
char			**ft_split(char const *s, char c);

int				ft_atoi(const char *str);
int				get_next_line(int fd, char **line);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *str);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strdup(const char *s1);

#endif
