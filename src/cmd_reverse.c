/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:30:18 by phwang            #+#    #+#             */
/*   Updated: 2024/02/28 17:23:55 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

void	reverse(t_pile **head, int choice)
{
	if (pile_count(*head) <= 1)
		return ;
	(*head) = (*head)->prev;
	if (choice == 0)
		ft_printf("rra\n");
	else if (choice == 1)
		ft_printf("rrb\n");
}

void	rereverse(t_pile **a, t_pile **b)
{
	(*a) = (*a)->prev;
	(*b) = (*b)->prev;
	ft_printf("rrr\n");
}
