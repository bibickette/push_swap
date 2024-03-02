/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:34:28 by phwang            #+#    #+#             */
/*   Updated: 2024/03/02 16:53:59 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

void	swap(t_pile **head, int choice)
{
	t_pile	*tempo;
	int		temp;

	tempo = (*head)->next;
	temp = tempo->number;
	tempo->number = (*head)->number;
	(*head)->number = temp;
	if (choice == 0)
		ft_printf("sa\n");
	else if (choice == 1)
		ft_printf("sb\n");
}

void	swaswap(t_pile **a, t_pile **b)
{
	swap(a, 2);
	swap(b, 2);
	ft_printf("ss\n");
}
