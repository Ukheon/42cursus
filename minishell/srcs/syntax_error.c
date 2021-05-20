/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:47:43 by hyeolee           #+#    #+#             */
/*   Updated: 2021/05/17 13:39:41 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int				check_syntax_error(char *line)
{
	if (quote_error_check(line))
		return (print_syntax_error(1));
	else if (option_error_check(line))
		return (print_syntax_error(2));
	else if (right_redir_error_check(line))
		return (print_syntax_error(3));
	else if (left_redir_error_check(line))
		return (print_syntax_error(4));
	else if (new_line_error_check(line))
		return (print_syntax_error(5));
	return (0);
}

int				print_syntax_error(int syntax_part)
{
	if (syntax_part == 1)
		ft_putstr_fd("syntax error in quote\n", 1);
	else if (syntax_part == 2)
		ft_putstr_fd("syntax error in option\n", 1);
	else if (syntax_part == 3)
		ft_putstr_fd("syntax error in right redirection\n", 1);
	else if (syntax_part == 4)
		ft_putstr_fd("syntax error in left redirection\n", 1);
	else if (syntax_part == 5)
		ft_putstr_fd("syntax error in newline\n", 1);
	else
		ft_putstr_fd("syntax error in etc\n", 1);
	return (1);
}
