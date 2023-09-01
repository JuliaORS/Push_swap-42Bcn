/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:42:37 by julolle-          #+#    #+#             */
/*   Updated: 2023/06/12 17:11:15 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_2(t_node **lst)
{
	if (check_sorted(*lst) == 1)
		return ;
	else
		ft_act_swap(lst, 1);
	if (check_sorted(*lst) == 1)
		return ;
	return ;
}

void	ft_sort_3(t_node **lst, t_stack *stack)
{
	if (check_sorted(*lst) == 1)
		return ;
	if ((*lst)->num < ft_lstlast(*lst)->num
		|| ((*lst)->num > (*lst)->next->num
			&& (*lst)->next->num > ft_lstlast(*lst)->num))
		ft_act_swap((lst), 1);
	if (check_sorted(*lst) == 1)
		return ;
	if ((*lst)->num > (*lst)->next->num)
		ft_act_rotate(lst, stack, 1);
	if (check_sorted(*lst) == 1)
		return ;
	if ((*lst)->num > ft_lstlast(*lst)->num)
		ft_act_revrot(lst, stack, 1);
	if (check_sorted(*lst) == 1)
		return ;
}

void	ft_sort_4(t_node **lst_a, t_node **lst_b, t_stack *st_a, t_stack *st_b)
{
	if (check_sorted(*lst_a) == 1)
		return ;
	if ((st_a->end->index == 4 || st_a->end->index == 1)
		&& ((*lst_a)->index != 1 || (*lst_a)->index != 4))
		ft_act_revrot(lst_a, st_a, 1);
	else if (((*lst_a)->next->index == 1 || (*lst_a)->next->index == 4)
		&& ((*lst_a)->index != 1 || (*lst_a)->index != 4))
		ft_act_swap(lst_a, 1);
	if (check_sorted(*lst_a) == 1)
		return ;
	if ((*lst_a)->index == 1 || (*lst_a)->index == 4)
	{	
		ft_act_push_b(lst_a, lst_b, st_a, st_b);
		ft_sort_3(lst_a, st_a);
		ft_act_push_a(lst_a, lst_b, st_a, st_b);
	}
	if (check_sorted(*lst_a) == 1)
		return ;
	if ((*lst_a)->index == 4)
		ft_act_rotate(lst_a, st_a, 1);
	if (check_sorted(*lst_a) == 1)
		return ;
}

void	ft_sort_5(t_node **lst_a, t_node **lst_b, t_stack *st_a, t_stack *st_b)
{
	if (check_sorted(*lst_a) == 1)
		return ;
	if (st_a->first->next->next->index == 5)
		ft_act_rotate(lst_a, st_a, 1);
	if (st_a->first->next->index == 5)
		ft_act_swap(lst_a, 1);
	if (st_a->end->prev->index == 5)
		ft_act_revrot(lst_a, st_a, 1);
	if (st_a->end->index == 5)
		ft_act_revrot(lst_a, st_a, 1);
	if (check_sorted(*lst_a) == 1)
		return ;
	if (st_a->first->index == 5)
	{	
		ft_act_push_b(lst_a, lst_b, st_a, st_b);
		ft_sort_4(lst_a, lst_b, st_a, st_b);
		ft_act_push_a(lst_a, lst_b, st_a, st_b);
		ft_act_rotate(lst_a, st_a, 1);
	}	
	if (check_sorted(*lst_a) == 1)
		return ;
}

int	check_sorted(t_node *lst)
{
	lst = lst->next;
	while (lst)
	{
		if (lst->prev->num > lst->num)
			return (0);
		lst = lst->next;
	}
	return (1);
}
