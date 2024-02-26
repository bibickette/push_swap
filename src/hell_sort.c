/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:16:00 by phwang            #+#    #+#             */
/*   Updated: 2024/02/26 23:57:04 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

void	hell_sort(t_pile **a, t_pile **b)
{
	while (pile_count(*a) > 3)
		push(a, b, 0);
	tiny_sort(a);
	set_pile(a, b);
}

// 1. push till 3 in a then tiny sort
// 2. set the cost to top of each
// 3. set the target of each
// now find cheapest with equivalent target