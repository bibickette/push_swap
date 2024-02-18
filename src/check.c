/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:31:15 by phwang            #+#    #+#             */
/*   Updated: 2024/02/18 17:04:41 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

char	**check_argv(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc <= 1 || (argc == 2 && !argv[1][0]))
		exit (-1);
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9') 
			&& argv[i][j] != ' ' && argv[i][j] != '-')
			{
				ft_printf("Error\n");
				exit (-1);
			}
		}
	}
	sign_check(argc, argv);
	if (argc == 2)
		argv = split(argv[1], ' ');
	return (argv);
}

void	sign_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if ((argv[i][j] == '-' && argv[i][j + 1] == '-') 
			|| (argv[i][j] != ' ' && argv[i][j + 1] == '-'))
			{
				ft_printf("Error\n");
				exit (-1);
			}
		}
	}
}

void	check_overflow(char **argv)
{
	int			i;
	
	i = 0;
	while (argv[++i])
	{
		if (ft_atoi(argv[i]) < -2147483648 || ft_atoi(argv[i]) > 2147483647)
		{
			ft_printf("Error\n");
			free_argv(argv);
			exit (-1);
		}
	}
}

void	free_argv(char **argv)
{
	int	size;
	
	size = 1;
	while (argv[size] != NULL)
		size++;
	while(--size >= 0)
		free(argv[size]);
	free(argv);
}