/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:12:28 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/07/04 12:00:18 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_a(t_list **stack_a)
{
	t_list	*last;
	t_list	*before_last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	last = *stack_a;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
}

void	rra(t_list **stack_a)
{
	reverse_a(stack_a);
	write(1, "rra\n", 4);
}

void	reverse_b(t_list **stack_b)
{
	t_list	*last;
	t_list	*before_last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	last = *stack_b;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
}

void	rrb(t_list **stack_b)
{
	reverse_b(stack_b);
	write(1, "rrb\n", 4);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	write(1, "rr\n", 3);
}
