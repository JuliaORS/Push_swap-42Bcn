/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:40:39 by julolle-          #+#    #+#             */
/*   Updated: 2023/06/12 17:13:09 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_node
{
	int				num;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node		*first;
	t_node		*end;
	int			size;
}	t_stack;

int				ft_check_errors(int argc, char **argv);
void			ft_push_swap(char **argv);
t_node			*ft_init_stack_a(char **argv, t_stack *stack_a);
t_node			*ft_get_index(t_node *list_a, t_stack *stack_a);
int				ft_isdigit(int c);
long long int	ft_atol(const char *str);
t_node			*ft_lstnew(int content);
int				ft_lstsize(t_node *lst);
void			ft_lstadd_back(t_node **lst, t_node *new);
t_node			*ft_lstlast(t_node *lst);
void			ft_lstclear(t_node **lst);
void			ft_stackclear(t_stack *stack);
int				ft_isnum(char **argv);
int				ft_isint(char **argv);
int				ft_no_rep(char **argv);
void			ft_mov_swap(t_node **lst);
void			ft_mov_push(t_node **adls, t_node **rmls, t_stack *adst,
					t_stack *rmst);
void			ft_aux_push(t_node **adls, t_node **rmls, t_stack *adst,
					t_stack *rmst);
void			ft_mov_rot(t_node **lst, t_stack *stack);
void			ft_mov_revrot(t_node **lst, t_stack *stack);
int				ft_act_swap(t_node **lst, int op);
int				ft_act_push_a(t_node **lst_a, t_node **lst_b, t_stack *st_a,
					t_stack *st_b);
int				ft_act_push_b(t_node **lst_a, t_node **lst_b, t_stack *st_a,
					t_stack *st_b);		
int				ft_act_rotate(t_node **lst, t_stack *stack, int op);
int				ft_act_revrot(t_node **lst, t_stack *stack, int op);
void			ft_free_stack(t_node **rmlst, t_stack rmst);
int				check_sorted(t_node *lst);
void			ft_sort_2(t_node **lst);
void			ft_sort_3(t_node **lst, t_stack *stack);
void			ft_sort_4(t_node **lst_a, t_node **lst_b, t_stack *st_a,
					t_stack *st_b);
void			ft_sort_5(t_node **lst_a, t_node **lst_b, t_stack *st_a,
					t_stack *st_b);
void			ft_sortbig(t_node **lst_a, t_node **lst_b, t_stack *st_a,
					t_stack *st_b);
void			create_sh(t_node **lst_a, t_node **lst_b, t_stack *st_a,
					t_stack *st_b);
int				ft_chunk_num(int size);
void			sort_sh(t_node **lst_a, t_node **lst_b, t_stack *st_a,
					t_stack *st_b);
int				ft_num_mov(t_node *lst_b, int index);
void			ft_free(t_node **lst_a, t_node **lst_b);

#endif