/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:50:28 by phwang            #+#    #+#             */
/*   Updated: 2024/02/18 18:36:56 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include "LIBFT/libft.h"
# include "LIBFT/ft_printf/ft_printf.h"

typedef struct l_pile
{
	int				number;
	struct l_pile	*next;
	struct l_pile	*prev;
}	t_pile;

char	**check_argv(int argc, char **argv);
void	sign_check(int argc, char **argv);
char	**split(char const *s, char c);

void	check_overflow(char **argv);
void	free_argv(char **argv);

int		argv_count(char **argv, int choice);

void	build_pile(t_pile **head, char **argv);
t_pile	*create_node(int num);
void	pile_addback(t_pile **head, t_pile *new);
void	make_it_circle(t_pile **head);
#endif