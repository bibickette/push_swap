/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:16:00 by phwang            #+#    #+#             */
/*   Updated: 2024/03/01 16:24:16 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

void	hell_sort(t_pile **a, t_pile **b)
{
	int		pile;

	mekherbo_magic(a, b);
	tiny_sort(a);
	pile = pile_count(*b) + 1;
	if (pile_count(*b) == 1)
	{
		handle_four(a, b);
		return ;
	}
	while (--pile > 1)
		more_hell(a, b);
	if (pile_count(*b) == 1)
		last_move(a, b);
}

void	more_hell(t_pile **a, t_pile **b)
{
	t_pile	*temp_b;
	t_pile	*target;
	int		cheapest;

	set_pile(a, b);
	temp_b = (*b);
	target = (*a);
	cheapest = find_cheapest(*b);
	while (temp_b->price != cheapest)
		temp_b = temp_b->next;
	while (temp_b->target_nb != target->number)
		target = target->next;
	make_move(a, b, temp_b, target);
}

void	make_move(t_pile **a, t_pile **b, t_pile *temp_b, t_pile *target)
{
	if (target->medium == temp_b->medium)
	{
		if (temp_b->medium == 1)
		{
			while (temp_b != (*b) && target != (*a))
				rorotate(a, b);
			while (temp_b != (*b))
				rotate(b, 1);
			while (target != (*a))
				rotate(a, 0);
			push(b, a, 1);
		}
		else if (temp_b->medium == 2)
			other_move(a, b, temp_b, target);
	}
	else if (target->medium != temp_b->medium)
		make_other_move(a, b, temp_b, target);
}

void	other_move(t_pile **a, t_pile **b, t_pile *temp_b, t_pile *target)
{
	while (temp_b != (*b) && target != (*a))
		rereverse(a, b);
	while (temp_b != (*b))
		reverse(b, 1);
	while (target != (*a))
		reverse(a, 0);
	push(b, a, 1);
}

void	make_other_move(t_pile **a, t_pile **b, t_pile *temp_b, t_pile *target)
{
	while (target != *a)
	{
		if (target->medium == 1)
			rotate(a, 0);
		else if (target->medium == 2)
			reverse(a, 0);
	}
	while (temp_b != *b)
	{
		if (temp_b->medium == 1)
			rotate(b, 1);
		else if (temp_b->medium == 2)
			reverse(b, 1);
	}
	push(b, a, 1);
}
