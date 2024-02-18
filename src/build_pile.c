/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:49:54 by phwang            #+#    #+#             */
/*   Updated: 2024/02/18 16:02:14 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

t_pile	*create_node(int num)
{
	t_pile *new;
	
	new = malloc(sizeof (t_pile));
	if(!new)
		return (0);
	new->number = (int *) malloc(sizeof(int));
	if (!(new->number))
		return (0);
	new->number = &num;
	return (new);
}


// 1 construire la pile :
// creer un element
// 	mettre le int dedans, si overflow = exit error 
// 	next = null previous = null
// positioner lelement :
// 	si !list : alors *head = lelement
// 	il y a 1 element : on recreer un element
// 	on va a la fin de la liste
// 	on actuel->next=new 
// 	on oublie pas position actuel et on va sur new 
// 	on new -> prev = actuel 
// 	on new -> next = null 
// si cest le dernier element a ajouter alors il faudra dire que 
// 	new -> next = head 
// 	head -> prev = new
	
	