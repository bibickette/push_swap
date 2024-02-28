/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:30:48 by phwang            #+#    #+#             */
/*   Updated: 2024/02/28 16:17:26 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

void	set_medium(t_pile *head)
{
	int	i;
	int	pile;

	pile = pile_count(head);
	i = -1;
	while (++i < pile)
	{
		if (head->position <= (pile / 2 + pile % 2))
			head->medium = 1;
		else if (head->position > (pile / 2 + pile % 2))
			head->medium = 2;
		head = head->next;
	}
}

void	set_position(t_pile *head)
{
	int	pos;
	int	pile;

	pile = pile_count(head);
	pos = 0;
	while (++pos <= pile)
	{
		head->position = pos;
		head = head->next;
	}
}
