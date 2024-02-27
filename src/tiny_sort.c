/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 23:52:18 by phwang            #+#    #+#             */
/*   Updated: 2024/02/27 14:04:05 by phwang           ###   ########.fr       */
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

