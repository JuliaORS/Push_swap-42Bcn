/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:08:06 by julolle-          #+#    #+#             */
/*   Updated: 2023/06/12 12:08:33 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int content)
{
	t_node	*newcont;

	newcont = (t_node *)malloc(sizeof(t_node));
	if (!newcont)
		return (NULL);
	newcont->num = content;
	newcont->next = NULL;
	newcont->prev = NULL;
	newcont->index = 0;
	return (newcont);
}

int	ft_lstsize(t_node *lst)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = lst;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*tmp;

	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			tmp = ft_lstlast(*lst);
			tmp->next = new;
			new->prev = tmp;
			new->next = NULL;
		}
		else
		{
			*lst = new;
			new->prev = NULL;
		}	
	}
}

t_node	*ft_lstlast(t_node *lst)
{
	t_node	*temp;

	temp = lst;
	if (!lst)
		return (NULL);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	ft_lstclear(t_node **lst)
{
	t_node	*temp;

	if (!(*lst))
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		free ((*lst));
		*lst = temp;
	}
}
