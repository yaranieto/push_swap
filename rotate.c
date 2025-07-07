/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:07:04 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/07/04 12:01:06 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_a)
{
	t_list	*first;
	t_list	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_list **stack_a)
{
	rotate_a(stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **stack_b)
{
	t_list	*first;
	t_list	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	*stack_b = first->next;
	last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rb(t_list **stack_b)
{
	rotate_b(stack_b);
	write(1, "rb\n", 3);
}
