/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 23:52:18 by phwang            #+#    #+#             */
/*   Updated: 2024/02/22 18:39:37 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

void	tiny_sort(t_pile **head)
{
	if ((*head)->number == find_low_num(*head)
		&& ((*head)->next)->number == find_top_num(*head))
	{
		swap(head, 0);
		rotate(head, 0);
	}
	else if (((*head)->number != find_low_num(*head))
		&& ((*head)->number != find_top_num(*head)))
	{
		if (((*head)->next)->number == find_top_num(*head))
			reverse(head, 0);
		else if (((*head)->next)->number == find_low_num(*head))
			swap(head, 0);
	}
	else if ((*head)->number == find_top_num(*head))
	{
		if (((*head)->next)->number == find_low_num(*head))
			rotate(head, 0);
		else
		{
			swap(head, 0);
			reverse(head, 0);
		}
	}
}

int	find_top_num(t_pile *head)
{
	t_pile	*temp;
	int		top_num;

	temp = head;
	top_num = -2147483648;
	if (temp->next == NULL)
		return (temp->number);
	if (temp->number > top_num)
		top_num = temp->number;
	temp = temp->next;
	while (temp != head)
	{
		if (temp->number > top_num)
			top_num = temp->number;
		temp = temp->next;
	}
	return (top_num);
}

int	find_low_num(t_pile *head)
{
	t_pile	*temp;
	int		low_num;

	temp = head;
	low_num = 2147483647;
	if (temp->next == NULL)
		return (temp->number);
	if (temp->number < low_num)
		low_num = temp->number;
	temp = temp->next;
	while (temp != head)
	{
		if (temp->number < low_num)
			low_num = temp->number;
		temp = temp->next;
	}
	return (low_num);
}
