/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:36:42 by phwang            #+#    #+#             */
/*   Updated: 2024/02/27 21:14:20 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

int	pile_count(t_pile *head)
{
	t_pile		*temp;
	int			size;

	if (!head)
		return (0);
	size = 1;
	temp = head;
	while (temp->next != head && temp->next != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

int	argv_count(char **argv, int choice)
{
	int	size;

	size = 0;
	if (choice == 0)
	{
		while (argv[size + 1] != NULL)
			size++;
		return (size);
	}
	return (-1);
}

/*alors la jai pas compris car si je rentre un chiffre, 
ça renvoie 0, mais un nombre renvoie 1*/