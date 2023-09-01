/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:40:45 by julolle-          #+#    #+#             */
/*   Updated: 2023/06/12 17:34:14 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(char **argv)
{
	t_node	*list_a;
	t_node	*list_b;
	t_stack	stack_a;
	t_stack	stack_b;

	list_a = ft_init_stack_a(argv, &stack_a);
	list_b = NULL;
	if (stack_a.size == 2)
		ft_sort_2(&list_a);
	else if (stack_a.size == 3)
		ft_sort_3(&list_a, &stack_a);
	else if (stack_a.size == 4)
		ft_sort_4(&list_a, &list_b, &stack_a, &stack_b);
	else if (stack_a.size == 5)
		ft_sort_5(&list_a, &list_b, &stack_a, &stack_b);
	else
		ft_sortbig(&list_a, &list_b, &stack_a, &stack_b);
	ft_free(&list_a, &list_b);
}

t_node	*ft_init_stack_a(char **argv, t_stack *stack_a)
{
	int		i;
	t_node	*list_a;

	i = 1;
	while (argv[i])
	{
		if (i == 1)
		{		
			list_a = ft_lstnew(ft_atol(argv[i]));
			if (!list_a)
				return (NULL);
		}
		else
			ft_lstadd_back(&list_a, ft_lstnew(ft_atol(argv[i])));
		i++;
	}
	stack_a->first = list_a;
	stack_a->end = ft_lstlast(list_a);
	stack_a->size = ft_lstsize(list_a);
	list_a = ft_get_index(list_a, stack_a);
	return (list_a);
}

t_node	*ft_get_index(t_node *list_a, t_stack *stack_a)
{
	int	index;
	int	lastnum;
	int	tmp;

	index = 1;
	lastnum = INT_MIN;
	while (index <= stack_a->size)
	{
		list_a = stack_a->first;
		tmp = INT_MAX;
		while (list_a)
		{
			if (list_a->num > lastnum && list_a->num <= tmp)
			{
				tmp = list_a->num;
				list_a->index = index;
			}		
			list_a = list_a->next;
		}
		lastnum = tmp;
		index++;
	}
	list_a = stack_a->first;
	return (list_a);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (ft_check_errors(argc, argv) == -1)
			write(1, "Error\n", 6);
		else
			ft_push_swap(argv);
	}
	return (0);
}
