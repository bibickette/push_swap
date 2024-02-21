/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:49:54 by phwang            #+#    #+#             */
/*   Updated: 2024/02/21 15:54:16 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

t_pile	*create_node(int num)
{
	t_pile	*new;

	new = malloc(sizeof (t_pile));
	if (!new)
		return (0);
	new->number = num;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	pile_addback(t_pile **head, t_pile *new)
{
	t_pile	*temp;

	if (!(*head))
		(*head) = new;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}

void	build_pile(t_pile **head, char **argv)
{
	int	size;
	int	i;

	i = 0;
	size = argv_count(argv, 0);
	while (++i <= size)
		pile_addback(&(*head), create_node(ft_atoi(argv[i])));
	make_it_circle(&(*head));
	free_argv(argv);
}

void	make_it_circle(t_pile **head)
{
	t_pile	*temp;

	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *head;
	(*head)->prev = temp;
}
