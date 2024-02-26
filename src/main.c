/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:49:48 by phwang            #+#    #+#             */
/*   Updated: 2024/02/26 23:56:00 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

void print_pile(t_pile *head, int choice)
{
	t_pile *temp;

	if (choice == 0)
	{
		temp = head;
		ft_printf("first list next: %d\n", temp->number);
		ft_printf("first list next target: %d\n", temp->target_nb);
		ft_printf("first list next cost: %d\n", temp->cost_to_top);
		if (temp->next != NULL)
			temp = temp->next;
		while(temp != head)
		{
			ft_printf("list next: %d\n", temp->number);
			ft_printf("list next target: %d\n", temp->target_nb);
			ft_printf("list next cost: %d\n", temp->cost_to_top);
			temp = temp->next;
		}
	}
	else if (choice == 1)
	{
		temp = head;
		ft_printf("first list prev: %d\n", temp->number);
		temp = temp->prev;
		while(temp != head)
		{
			ft_printf("list prev: %d\n", temp->number);
			temp = temp->prev;
		}
	}
}

int	main(int argc, char **argv)
{
	t_pile	*a = NULL;
	t_pile	*b = NULL;

	argv = argv_check(argc, argv);
	build_pile(&a, argv);
	hell_sort(&a, &b);
	print_pile(a, 0);
	print_pile(b, 0);
	// free_pile(a, a);
	// free_pile(b, b);
}

/* si on rentre seulement 1 nombre , ca fait rien*/