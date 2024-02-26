/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:30:17 by phwang            #+#    #+#             */
/*   Updated: 2024/02/26 23:55:21 by phwang           ###   ########.fr       */
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
}

void	set_target(t_pile **b, t_pile **a_targeted)
{
	/* so the target is the next superior number of the one we base*/
	t_pile	*temp_target;
	t_pile	*temp_b;
	
	temp_target = (*a_targeted);
	temp_b = (*b);
	if (temp_b->next == NULL)
		return;
	while (temp_target->number != smallest_next(*a_targeted, temp_b->number))
		temp_target = temp_target->next;
	temp_b->target_nb = temp_target->number;
	temp_b = temp_b->next;
	while (temp_b != (*b))
	{
		while (temp_target->number != smallest_next(*a_targeted, temp_b->number))
			temp_target = temp_target->next;
		temp_b->target_nb = temp_target->number;
		temp_b = temp_b->next;	
	}
	
}

void	set_cost_top(t_pile **head)
{
	int		i;
	t_pile	*temp;

	i = 0;
	temp = (*head);
	while ( i <= (pile_count(*head) / 2 + pile_count(*head) % 2))
	{
		temp->cost_to_top = i;
		temp = temp->next;
		i++;
	}
	i = 0;
	temp = (*head);
	while (i <= pile_count(*head) / 2)
	{
		temp->cost_to_top = i;
		temp = temp->prev;
		i++;
	}
}

int	smallest_next(t_pile *head, int base)
{
	t_pile	*temp;
	int		small_potent;

	temp = head;
	small_potent = head->number;
	temp = temp->next;
	while (temp != head)
	{
		if (highest_nb(head) < temp->number)
			small_potent = smallest_nb(head);
		else if (((temp->number > base) && (temp->number - base) < (small_potent - base))
		|| small_potent < base)
			small_potent = temp->number;
		temp = temp->next;
	}
	return (small_potent);
}