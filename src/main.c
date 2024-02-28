/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:49:48 by phwang            #+#    #+#             */
/*   Updated: 2024/02/28 19:46:17 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

int	main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;

	a = NULL;
	b = NULL;
	argv = argv_check(argc, argv);
	build_pile(&a, argv);
	hell_sort(&a, &b);
	free_pile(a, a);
}

// #include <time.h>
/* si on rentre seulement 1 nombre , ca fait rien*/

	// starttime = (float)clock()/CLOCKS_PER_SEC;
	// hell_sort(&a, &b);
	// endtime = (float)clock()/CLOCKS_PER_SEC;
	// timeelapsed = endtime - starttime;
	// __builtin_printf("temps 3 :%f\n", timeelapsed);