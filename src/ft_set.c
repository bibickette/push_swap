/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:30:17 by phwang            #+#    #+#             */
/*   Updated: 2024/02/28 17:30:53 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

void	set_pile(t_pile **a, t_pile **b)
{
	set_target(b, a);
	set_cost_top(a);
	set_cost_top(b);
	set_position(*a);
	set_position(*b);
	set_medium(*a);
	set_medium(*b);
	set_price(*b, *a);
}

void	set_target(t_pile **b, t_pile **a_targeted)
{
	t_pile	*temp_target;
	t_pile	*temp_b;
	int		smallest;

	temp_target = (*a_targeted);
	temp_b = (*b);
	if (temp_b->next == NULL)
		return ;
	smallest = smallest_next(*a_targeted, temp_b->number);
	while (temp_target->number != smallest)
		temp_target = temp_target->next;
	temp_b->target_nb = temp_target->number;
	temp_b = temp_b->next;
	while (temp_b != (*b))
	{
		smallest = smallest_next(*a_targeted, temp_b->number);
		while (temp_target->number != smallest)
			temp_target = temp_target->next;
		temp_b->target_nb = temp_target->number;
		temp_b = temp_b->next;
	}
}

void	set_cost_top(t_pile **head)
{
	int		i;
	int		medium;
	int		pile;
	t_pile	*temp;

	i = -1;
	pile = pile_count(*head);
	medium = (pile / 2 + pile % 2);
	temp = (*head);
	while (++i <= medium)
	{
		temp->cost_to_top = i;
		temp = temp->next;
	}
	i = -1;
	temp = (*head);
	medium = pile / 2;
	while (++i <= medium)
	{
		temp->cost_to_top = i;
		temp = temp->prev;
	}
}

void	set_price(t_pile *b, t_pile *a)
{
	int	i;
	int	pile;

	pile = pile_count(b);
	i = -1;
	while (++i < pile)
	{
		while (a->number != b->target_nb)
			a = a->next;
		if (a->medium == b->medium)
		{
			if (b->cost_to_top > a->cost_to_top)
				b->price = b->cost_to_top;
			else
				b->price = a->cost_to_top;
		}
		else
			b->price = b->cost_to_top + a->cost_to_top;
		b = b->next;
	}
}
