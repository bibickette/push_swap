/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 00:48:34 by phwang            #+#    #+#             */
/*   Updated: 2024/03/16 19:46:37 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define FALSE 0
# define TRUE 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct l_list
{
	char			*content;
	struct l_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		first_step(int fd, t_list **head, char **stock);
int		stock_analyse(char *stock);
int		ft_read(int fd, t_list **head, char **stock);
int		n_stock(t_list **head, char **stock, int fd);
int		separate_stock(t_list **head, char **stock);
void	*build_line(t_list *head, char **line, char *stock);

t_list	*ft_lstnew(char **stock);
void	ft_lstclear(t_list **head);
void	ft_lstadd_back(t_list **head, t_list *elem);
int		ft_len(t_list *head, char *stock, int choice);

#endif