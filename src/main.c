/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:49:48 by phwang            #+#    #+#             */
/*   Updated: 2024/02/18 19:53:44 by phwang           ###   ########.fr       */
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
		ft_printf("list 0: %d\n", temp->number);
		temp = temp->next;
		while(temp != head)
		{
			ft_printf("list 0: %d\n", temp->number);
			temp = temp->next;
		}
	}
	else if (choice == 1)
	{
		temp = head;
		ft_printf("list 1: %d\n", temp->number);
		temp = temp->prev;
		while(temp != head)
		{
			ft_printf("list 1: %d\n", temp->number);
			temp = temp->prev;
		}
	}
}

int	main(int argc, char **argv)
{
	t_pile	*a = NULL;

	argv = argv_check(argc, argv);
	build_pile(&a, argv);
	print_pile(a, 0);
	print_pile(a, 1);
	free_pile(a, a);
}
