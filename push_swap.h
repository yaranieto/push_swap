/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:07:11 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/07/04 12:13:08 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

typedef struct s_list
{
	int				data;
	int				index;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}	t_list;
int		stack_size(t_list *stack);
int		find_min(t_list *stack);
void	error_exit(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	reverse_a(t_list **stack_a);
void	reverse_b(t_list **stack_b);
void	cheap_moves(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b);
void	rev_both(t_list **stack_a, t_list **stack_b, int *cost_a,
			int *cost_b);
void	rot_both(t_list **stack_a, t_list **stack_b, int *cost_a,
			int *cost_b);
void	rot_a(t_list **stack_a, int *cost);
void	rot_b(t_list **stack_b, int *cost);
void	costs(t_list **stack_a, t_list **stack_b);
void	short_move(t_list **stack_a, t_list	**stack_b);
int		is_negative(int nbr);
int		is_valid_arg(char *str);
int		is_duplicate(t_list *stack, int value);
t_list	*parse_args(int argc, char **argv, int i);
t_list	*ft_new_node(int data);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd(t_list **stack, t_list *new);
long	ft_atol(char *str);
void	free_stack(t_list **stack);
int		is_sorted(t_list *stack);
void	push_swap(t_list **stack_a, t_list **stack_b, int stack_size);
void	sort_three(t_list **stack_a);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	sort_two(t_list	**stack_a);
void	sort(t_list **stack_a, t_list **stack_b);
char	**ft_split(const char *s, char c);
void	free_split(char	**str);
void	one_arg(t_list **stack_a, char **argv);
void	bring_min_to_top(t_list **stack, int min);
int		get_position(t_list *stack, int value);
void	index_stack(t_list *stack);
void	push_init(t_list **stack_a, t_list **stack_b);
void	set_position(t_list **stack);
void	set_target(t_list **stack_a, t_list **stack_b);
int		get_target(t_list *stack_a, int stack_b_index);
