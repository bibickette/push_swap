/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 23:52:18 by phwang            #+#    #+#             */
/*   Updated: 2024/02/26 21:13:07 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

void	tiny_sort(t_pile **head)
{
	if ((*head)->number == highest_nb(*head))
		rotate(head, 0);
	else if ((*head)->next->number == highest_nb(*head))
		reverse(head, 0);
	if ((*head)->number > (*head)->next->number)
		swap(head, 0);
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
