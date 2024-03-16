/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 00:49:17 by phwang            #+#    #+#             */
/*   Updated: 2024/03/16 20:21:14 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../get_next_line.h"

int	stock_analyse(char *stock)
{
	int	i;

	i = 0;
	if (stock[i] == '\0')
		return (0);
	while (stock[i])
	{
		if (stock[i] == '\n')
			return (1);
		i++;
	}
	return (2);
}

void	ft_lstadd_back(t_list **head, t_list *elem)
{
	t_list	*temp;

	if (!(*head))
		(*head) = elem;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = elem;
	}
}

t_list	*ft_lstnew(char **stock)
{
	t_list	*new;
	int		len;

	len = 0;
	new = malloc(sizeof (t_list));
	if (!new)
		return (0);
	while ((*stock)[len])
		len++;
	new->content = malloc((len + 1) * sizeof (char));
	if (!(new->content))
		return (0);
	len = -1;
	while ((*stock)[++len])
		new->content[len] = (*stock)[len];
	new->content[len] = '\0';
	new->next = NULL;
	free(*stock);
	*stock = 0;
	return (new);
}

void	ft_lstclear(t_list **head)
{
	if (*head != NULL)
	{
		ft_lstclear(&((*head)->next));
		if ((*head)->content != NULL)
		{
			free((*head)->content);
			(*head)->content = NULL;
		}
		free(*head);
		*head = NULL;
	}
}

int	ft_len(t_list *head, char *stock, int choice)
{
	int	len;

	len = 0;
	if (choice == 0)
	{
		if (head == NULL)
			return (0);
		while ((head->content)[len])
			len++;
		return (len + ft_len(head->next, stock, 0));
	}
	else if (choice == 1)
	{
		while (stock[len])
			len++;
		return (len);
	}
	return (0);
}
