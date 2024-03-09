/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:16:16 by phwang            #+#    #+#             */
/*   Updated: 2024/03/09 01:24:51 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

void	print_pile(t_pile *head)
{
	t_pile	*temp;
	int		i;

	i = 2;
	temp = head;
	ft_printf("first list :	 %d\n", temp->number);
	if (temp->next != NULL)
		temp = temp->next;
	while (temp != head)
	{
		ft_printf("list %d		: %d\n", i, temp->number);
		temp = temp->next;
		i++;
	}
}
