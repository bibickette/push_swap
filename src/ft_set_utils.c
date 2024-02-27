/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:30:48 by phwang            #+#    #+#             */
/*   Updated: 2024/02/27 22:23:48 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

void	set_medium(t_pile *head)
{
	int	i;

	i = -1;
	while (++i < pile_count(head))
	{
		if (head->position <= (pile_count(head) / 2 + pile_count(head) % 2))
			head->medium = 1;
		else if (head->position > (pile_count(head) / 2 + pile_count(head) % 2))
			head->medium = 2;
		head = head->next;
	}
}

void	set_position(t_pile *head)
{
	int	pos;

	pos = 0;
	while (++pos <= pile_count(head))
	{
		head->position = pos;
		head = head->next;
	}
}
