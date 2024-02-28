/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:50:28 by phwang            #+#    #+#             */
/*   Updated: 2024/02/28 19:35:47 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "LIBFT/libft.h"
# include "LIBFT/ft_printf/ft_printf.h"

typedef struct l_pile
{
	int				number;
	int				cost_to_top;
	int				target_nb;
	int				price;
	int				position;
	int				medium;
	struct l_pile	*next;
	struct l_pile	*prev;
}	t_pile;

/**************/
/* BUILD_PILE */
/**************/
void	build_pile(t_pile **head, char **argv);
t_pile	*create_node(int num);
void	pile_addback(t_pile **head, t_pile *new);
void	make_it_circle(t_pile **head);
/*********/
/* CHECK */
/*********/
char	**argv_check(int argc, char **argv);
void	sign_check(int argc, char **argv);
void	overflow_check(char **argv);
void	twin_check(char **argv);

/***********/
/* FT FREE */
/***********/
void	free_argv(char **argv);
void	free_pile(t_pile *head, t_pile *current);

/************/
/* FT COUNT */
/************/
int		argv_count(char **argv, int choice);
int		pile_count(t_pile *head);

/*************************/
/* 			CMD			 */
/*************************/
/********/
/* PUSH */
/********/
void	push(t_pile **this, t_pile **onthis, int choice);
void	pile_addfront(t_pile **head, t_pile *element);
t_pile	*extract_head(t_pile **head);
/********/
/* SWAP */
/********/
void	swap(t_pile **head, int choice);
void	swaswap(t_pile **a, t_pile **b);
/**********/
/* ROTATE */
/**********/
void	rotate(t_pile **head, int choice);
void	rorotate(t_pile **a, t_pile **b);
/***********/
/* REVERSE */
/***********/
void	reverse(t_pile **head, int choice);
void	rereverse(t_pile **a, t_pile **b);

/**********/
/* FT SET */
/**********/
void	set_pile(t_pile **a, t_pile **b);
void	set_target(t_pile **b, t_pile **a_targeted);
void	set_cost_top(t_pile **head);
void	set_price(t_pile *b, t_pile *a);
/****************/
/* FT SET UTILS */
/****************/
void	set_position(t_pile *head);
void	set_medium(t_pile *head);

/***********/
/* FT FIND */
/***********/
int		smallest_next(t_pile *head, int base);
int		find_cheapest(t_pile *head);
int		highest_nb(t_pile *head);
int		smallest_nb(t_pile *head);

/****************************/
/* HELL HELL HELL HELL HELL */
/****************************/
/*************/
/* HELL SORT */
/*************/
void	hell_sort(t_pile **a, t_pile **b);
void	more_hell(t_pile **a, t_pile **b);
void	make_move(t_pile **a, t_pile **b, t_pile *temp_b, t_pile *target);
void	other_move(t_pile **a, t_pile **b, t_pile *temp_b, t_pile *target);
void	make_other_move(t_pile **a, t_pile **b, t_pile *temp_b, t_pile *target);
/*************/
/* MORE HELL */
/*************/
void	last_move(t_pile **a, t_pile **b);
void	put_min_top(t_pile **a);
void	handle_four(t_pile **a, t_pile **b);
/*************/
/* TINY SORT */
/*************/
void	tiny_sort(t_pile **head);

/**********/
/* OTHERS */
/**********/
void	print_pile(t_pile *a);
char	**split(char const *s, char c);

#endif