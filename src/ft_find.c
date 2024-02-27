/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:03:22 by phwang            #+#    #+#             */
/*   Updated: 2024/02/27 21:38:36 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

int	smallest_next(t_pile *head, int base)
{
	t_pile	*temp;
	int		small_potent;

	temp = head;
	small_potent = head->number;
	temp = temp->next;
	while (temp != head)
	{
		if (highest_nb(head) < base)
			return (smallest_nb(head));
		else if (((temp->number > base)
				&& (temp->number - base) < (small_potent - base))
			|| small_potent < base)
			small_potent = temp->number;
		temp = temp->next;
	}
	return (small_potent);
}

int	highest_nb(t_pile *head)
{
	t_pile	*temp;
	int		top_num;

	temp = head;
	top_num = -2147483648;
	if (temp->next == NULL)
		return (temp->number);
	if (temp->number > top_num)
		top_num = temp->number;
	if (temp->next != NULL)
		temp = temp->next;
	while (temp != head)
	{
		if (temp->number > top_num)
			top_num = temp->number;
		temp = temp->next;
	}
	return (top_num);
}

int	smallest_nb(t_pile *head)
{
	t_pile	*temp;
	int		low_num;

	temp = head;
	low_num = 2147483647;
	if (temp->next == NULL)
		return (temp->number);
	if (temp->number < low_num)
		low_num = temp->number;
	if (temp->next != NULL)
		temp = temp->next;
	while (temp != head)
	{
		if (temp->number < low_num)
			low_num = temp->number;
		temp = temp->next;
	}
	return (low_num);
}

int	find_cheapest(t_pile *head)
{
	int		cheapest;
	t_pile	*temp;

	cheapest = head->price;
	temp = head;
	temp = temp->next;
	while (temp != head)
	{
		if (temp->price < cheapest)
			cheapest = temp->price;
		temp = temp->next;
	}
	return (cheapest);
}
