/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:31:15 by phwang            #+#    #+#             */
/*   Updated: 2024/02/29 16:36:40 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

char	**argv_check(int argc, char **argv)
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
	overflow_check(argv);
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

void	overflow_check(char **argv)
{
	int	i;

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
	if (argv_count(argv, 0) <= 1)
	{
		free_argv(argv);
		exit (0);
	}
	twin_check(argv);
}

void	twin_check(char **argv)
{
	int	num;
	int	i;
	int	pos;

	pos = 0;
	while (++pos <= argv_count(argv, 0))
	{
		i = 0;
		num = ft_atoi(argv[pos]);
		while (++i <= argv_count(argv, 0))
		{
			if (num == ft_atoi(argv[i]) && i != pos)
			{
				ft_printf("Error\n");
				free_argv(argv);
				exit(-1);
			}
		}
	}
}
