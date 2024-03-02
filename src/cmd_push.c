/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:35:37 by phwang            #+#    #+#             */
/*   Updated: 2024/03/02 16:57:17 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

void	push(t_pile **this, t_pile **onthis, int choice)
{
	if (!(*this))
		return ;
	pile_addfront(onthis, extract_head(this));
	if (choice == 0)
		ft_printf("pb\n");
	else if (choice == 1)
		ft_printf("pa\n");
}

void	pile_addfront(t_pile **head, t_pile *element)
{
	t_pile	*last;
	t_pile	*cur_first;

	if (!(*head))
		(*head) = element;
	else
	{
		if ((*head)->next == NULL)
		{
			last = (*head);
			cur_first = last;
		}
		else
		{
			last = (*head)->prev;
			cur_first = (*head);
		}
		last->next = element;
		element->prev = last;
		element->next = cur_first;
		cur_first->prev = element;
		(*head) = element;
	}
}

t_pile	*extract_head(t_pile **head)
{
	t_pile	*extracted;
	t_pile	*last;
	t_pile	*second;

	extracted = (*head);
	last = (*head)->prev;
	second = (*head)->next;
	last->next = second;
	second->prev = last;
	(*head) = second;
	extracted->next = NULL;
	extracted->prev = NULL;
	return (extracted);
}
