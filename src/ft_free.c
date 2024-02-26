/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:11:56 by phwang            #+#    #+#             */
/*   Updated: 2024/02/26 14:12:17 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

void	free_argv(char **argv)
{
	int	size;

	size = argv_count(argv, 0) + 1;
	if (argv[0] == NULL)
	{
		while (--size >= 0)
			free(argv[size]);
		free(argv);
	}
}

void	free_pile(t_pile *head, t_pile *current)
{
	t_pile	*temp;

	if (head)
	{
		temp = current->next;
		free(current);
		current = NULL;
		if (temp != head)
			free_pile(head, temp);
	}
}
