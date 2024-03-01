/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell_mekherbo_magic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:11:46 by phwang            #+#    #+#             */
/*   Updated: 2024/03/01 16:12:44 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

void	mekherbo_magic(t_pile **a, t_pile **b)
{
	int	pushed;
	int	pile_size;
	int	len_tmp;

	pushed = 0;
	pile_size = pile_count(*a);
	len_tmp = pile_size;
	while (pile_size > 6 && pushed < len_tmp / 2)
	{
		if ((*a)->number < len_tmp / 2)
		{
			push(a, b, 0);
			pushed++;
		}
		else
			rotate(a, 0);
		pile_size--;
	}
	while (len_tmp - pushed > 3)
	{
		push(a, b, 0);
		pushed++;
	}
}
