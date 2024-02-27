/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_hell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:53:39 by phwang            #+#    #+#             */
/*   Updated: 2024/02/27 22:22:36 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

void	last_move(t_pile **a, t_pile **b)
{
	t_pile	*temp;

	set_medium(*a);
	temp = (*a);
	while (temp->number != smallest_next(*a, (*b)->number))
		temp = temp->next;
	while ((*a)->number != smallest_next(*a, (*b)->number))
	{
		if (temp->medium == 1)
			rotate(a, 0);
		else if (temp->medium == 2)
			reverse(a, 0);
	}
	push(b, a, 1);
	put_min_top(a);
}

void	put_min_top(t_pile **a)
{
	t_pile	*temp;

	set_medium(*a);
	temp = (*a);
	while (temp->number != smallest_nb(*a))
		temp = temp->next;
	while ((*a)->number != smallest_nb(*a))
	{
		if (temp->medium == 1)
			rotate(a, 0);
		else if (temp->medium == 2)
			reverse(a, 0);
	}
}

void	handle_four(t_pile **a, t_pile **b)
{
	if ((*a)->prev->number == smallest_next(*a, (*b)->number))
		reverse(a, 0);
	else if ((*a)->next->number == smallest_next(*a, (*b)->number))
		rotate(a, 0);
	pile_addfront(a, *b);
	ft_printf("pa\n");
	while ((*a)->number != smallest_nb(*a))
	{
		if ((*a)->next->number == smallest_nb(*a))
			rotate(a, 0);
		else
			reverse(a, 0);
	}
}
