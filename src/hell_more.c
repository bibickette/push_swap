/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:53:39 by phwang            #+#    #+#             */
/*   Updated: 2024/03/01 16:11:43 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

void	last_move(t_pile **a, t_pile **b)
{
	t_pile	*temp;
	int		smallest;

	smallest = smallest_next(*a, (*b)->number);
	set_medium(*a);
	temp = (*a);
	while (temp->number != smallest)
		temp = temp->next;
	while ((*a)->number != smallest)
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
	int		smallest;

	set_medium(*a);
	temp = (*a);
	smallest = smallest_nb(*a);
	while (temp->number != smallest)
		temp = temp->next;
	while ((*a)->number != smallest)
	{
		if (temp->medium == 1)
			rotate(a, 0);
		else if (temp->medium == 2)
			reverse(a, 0);
	}
}

void	handle_four(t_pile **a, t_pile **b)
{
	int		small;
	int		small_nb;

	small = smallest_next(*a, (*b)->number);
	small_nb = smallest_nb(*a);
	if ((*a)->prev->number == small)
		reverse(a, 0);
	else if ((*a)->next->number == small)
		rotate(a, 0);
	pile_addfront(a, *b);
	ft_printf("pa\n");
	while ((*a)->number != small_nb)
	{
		if ((*a)->next->number == small_nb)
			rotate(a, 0);
		else
			reverse(a, 0);
	}
}
