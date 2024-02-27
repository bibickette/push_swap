/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:49:48 by phwang            #+#    #+#             */
/*   Updated: 2024/02/27 16:23:14 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

void print_pile(t_pile *head, int choice)
{
	t_pile *temp;
	int i = 2;
	if (choice == 0)
	{
		temp = head;
		ft_printf("first list next:	 %d\n", temp->number);
		ft_printf("first target: %d\n", temp->target_nb);
		ft_printf("first price: %d\n", temp->price);
		ft_printf("first position: %d\n", temp->position);
		if (temp->next != NULL)
			temp = temp->next;
		while(temp != head)
		{
			ft_printf("list %d			: %d\n",i, temp->number);
			ft_printf("list %d target: %d\n", i, temp->target_nb);
			ft_printf("list %d price: %d\n", i, temp->price);
			ft_printf("list %d position: %d\n", i, temp->position);
			temp = temp->next;
			i++;
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