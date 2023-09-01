/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:33:15 by julolle-          #+#    #+#             */
/*   Updated: 2023/06/12 17:10:40 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mov_swap(t_node **lst)
{
	int	tmp_num;
	int	tmp_index;

	if (ft_lstsize((*lst)) > 1)
	{
		tmp_num = (*lst)->num;
		tmp_index = (*lst)->index;
		(*lst)->num = (*lst)->next->num;
		(*lst)->index = (*lst)->next->index;
		(*lst)->next->num = tmp_num;
		(*lst)->next->index = tmp_index;
	}
}

void	ft_mov_push(t_node **adls, t_node **rmls, t_stack *adst, t_stack *rmst)
{
	t_node	*tmp_rm;

	if (!(*adls))
		ft_aux_push(adls, rmls, adst, rmst);
	else
	{
		if (rmst->size > 1)
			tmp_rm = (*rmls)->next;
		(*adls)->prev = (*rmls);
		(*adls) = (*rmls);
		(*adls)->next = adst->first;
		(*adls)->prev = NULL;
		adst->first = (*adls);
		adst->size = ft_lstsize((*adls));
		if (rmst->size == 1)
			(*rmls) = NULL;
		else
		{
			(*rmls) = tmp_rm;
			(*rmls)->prev = NULL;
			rmst->first = (*rmls);
			rmst->size = ft_lstsize((*rmls));
		}
	}
}

void	ft_aux_push(t_node **adls, t_node **rmls, t_stack *adst, t_stack *rmst)
{
	t_node	*tmp_rm;

	tmp_rm = (*rmls)->next;
	(*adls) = (*rmls);
	(*adls)->next = NULL;
	adst->end = (*adls);
	(*adls)->prev = NULL;
	adst->first = (*adls);
	adst->size = ft_lstsize((*adls));
	(*rmls) = tmp_rm;
	(*rmls)->prev = NULL;
	rmst->first = (*rmls);
	rmst->size = ft_lstsize((*rmls));
}

void	ft_mov_rot(t_node **lst, t_stack *stack)
{
	t_node	*tmp;
	t_node	*last;

	if (ft_lstsize((*lst)) > 1)
	{
		tmp = (*lst);
		last = ft_lstlast((*lst));
		(*lst) = (*lst)->next;
		(*lst)->prev = NULL;
		ft_lstadd_back(lst, tmp);
		stack->first = (*lst);
		stack->end = tmp;
	}
}

void	ft_mov_revrot(t_node **lst, t_stack *stack)
{
	t_node	*last;

	if (ft_lstsize((*lst)) > 1)
	{
		last = ft_lstlast((*lst));
		(*lst)->prev = last;
		last = last->prev;
		last->next = NULL;
		(*lst) = (*lst)->prev;
		(*lst)->next = stack->first;
		(*lst)->prev = NULL;
		stack->first = (*lst);
		stack->end = last;
	}
}
