/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:29:12 by julolle-          #+#    #+#             */
/*   Updated: 2023/06/07 12:10:07 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_act_swap(t_node **lst, int op)
{
	ft_mov_swap(lst);
	if (op == 1)
		write(1, "sa\n", 3);
	else if (op == 2)
		write(1, "sb\n", 3);
	return (0);
}

int	ft_act_push_a(t_node **lst_a, t_node **lst_b, t_stack *st_a, t_stack *st_b)
{
	ft_mov_push(lst_a, lst_b, st_a, st_b);
	write(1, "pa\n", 3);
	return (0);
}

int	ft_act_push_b(t_node **lst_a, t_node **lst_b, t_stack *st_a, t_stack *st_b)
{
	ft_mov_push(lst_b, lst_a, st_b, st_a);
	write(1, "pb\n", 3);
	return (0);
}

int	ft_act_rotate(t_node **lst, t_stack *stack, int op)
{
	ft_mov_rot(lst, stack);
	if (op == 1)
		write(1, "ra\n", 3);
	else if (op == 2)
		write(1, "rb\n", 3);
	return (0);
}

int	ft_act_revrot(t_node **lst, t_stack *stack, int op)
{
	ft_mov_revrot(lst, stack);
	if (op == 1)
		write(1, "rra\n", 4);
	else if (op == 2)
		write(1, "rrb\n", 4);
	return (0);
}
