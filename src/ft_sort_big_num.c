/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:23:24 by julolle-          #+#    #+#             */
/*   Updated: 2023/06/12 16:19:59 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sortbig(t_node **lst_a, t_node **lst_b, t_stack *st_a, t_stack *st_b)
{
	if (check_sorted(*lst_a) == 1)
		return ;
	create_sh(lst_a, lst_b, st_a, st_b);
	sort_sh(lst_a, lst_b, st_a, st_b);
}

int	ft_chunk_num(int size)
{
	int	chunk_num;

	if (5 < size && size <= 100)
		chunk_num = 5;
	else if (100 < size && size <= 500)
		chunk_num = 11;
	else
		chunk_num = 16;
	return (chunk_num);
}

void	create_sh(t_node **lst_a, t_node **lst_b, t_stack *st_a, t_stack *st_b)
{
	int	i;
	int	size_chunk;
	int	chunk_max;

	size_chunk = st_a->size / ft_chunk_num(st_a->size);
	chunk_max = st_a->size / ft_chunk_num(st_a->size);
	while (chunk_max < st_a->size + st_b->size)
	{
		i = 0;
		while (i < size_chunk)
		{
			if ((*lst_a)->index <= chunk_max)
			{
				ft_act_push_b(lst_a, lst_b, st_a, st_b);
				if ((*lst_b)->index < (chunk_max - (size_chunk / 2)))
					ft_act_rotate(lst_b, st_b, 2);
				i++;
			}
			else
				ft_act_rotate(lst_a, st_a, 1);
		}
		chunk_max = chunk_max + size_chunk;
	}
	while ((*lst_a) != NULL)
		ft_act_push_b(lst_a, lst_b, st_a, st_b);
}	

int	ft_num_mov(t_node *lst_b, int index)
{
	int		num_mov;

	num_mov = 0;
	while (lst_b->index != index)
	{
		num_mov++;
		lst_b = lst_b->next;
	}
	return (num_mov);
}

void	sort_sh(t_node **lst_a, t_node **lst_b, t_stack *st_a, t_stack *st_b)
{
	int	in;

	in = st_b->size;
	while (in >= 1)
	{
		while ((*lst_b)->index != in)
		{
			if ((*lst_b)->index == in - 1)
				ft_act_push_a(lst_a, lst_b, st_a, st_b);
			else if (ft_num_mov((*lst_b), in) < st_b->size / 2)
				ft_act_rotate(lst_b, st_b, 2);
			else
				ft_act_revrot(lst_b, st_b, 2);
		}
		ft_act_push_a(lst_a, lst_b, st_a, st_b);
		if ((*lst_a) != st_a->end && (*lst_a)->index > (*lst_a)->next->index)
		{
			ft_act_swap(lst_a, 1);
			in--;
		}
		in--;
	}
}
