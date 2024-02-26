/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:34:28 by phwang            #+#    #+#             */
/*   Updated: 2024/02/21 18:45:36 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

void	swap(t_pile **head, int choice)
{
	t_pile	*tempo;
	int		temp;

	if (pile_count(*head) <= 1)
		return ;
	tempo = (*head)->next;
	temp = tempo->number;
	tempo->number = (*head)->number;
	(*head)->number = temp;
	print_swap(choice);
}

void	swaswap(t_pile **a, t_pile **b)
{
	swap(a, 2);
	swap(b, 2);
	ft_printf("ss\n");
}

void	print_swap(int choice)
{
	if (choice == 0)
		ft_printf("sa\n");
	else if (choice == 1)
		ft_printf("sb\n");
}
