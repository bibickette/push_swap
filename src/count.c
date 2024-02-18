/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:36:42 by phwang            #+#    #+#             */
/*   Updated: 2024/02/18 19:49:25 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

int	argv_count(char **argv, int choice)
{
	int	size;

	size = 0;
	if (choice == 0)
	{
		while (argv[size + 1] != NULL)
			size ++;
		return (size);
	}
	return (-1);
}

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
