/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:50:28 by phwang            #+#    #+#             */
/*   Updated: 2024/02/11 19:40:08 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include "LIBFT/libft.h"
# include "LIBFT/ft_printf/ft_printf.h"

typedef struct l_pile
{
	int				*number;
	struct l_pile	*next;
	struct l_pile	*prev;
}	t_pile;

char **check_argv(int argc, char **argv);
void	sign_check(int argc, char **argv);


#endif