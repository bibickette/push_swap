/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:23:25 by phwang            #+#    #+#             */
/*   Updated: 2024/02/28 17:23:28 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

void	rotate(t_pile **head, int choice)
{
	if (pile_count(*head) <= 1)
		return ;
	(*head) = (*head)->next;
	if (choice == 0)
		ft_printf("ra\n");
	else if (choice == 1)
		ft_printf("rb\n");
}

void	rorotate(t_pile **a, t_pile **b)
{
	(*a) = (*a)->next;
	(*b) = (*b)->next;
	ft_printf("rr\n");
}
