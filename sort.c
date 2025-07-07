/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:23:54 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/07/04 12:19:16 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list	**stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a);
}

void	sort_three(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->data;
	second = (*stack_a)->next->data;
	third = (*stack_a)->next->next->data;
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = find_min(*stack_a);
	while ((*stack_a)->data != min)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min1;
	int	min2;

	min1 = find_min(*stack_a);
	bring_min_to_top(stack_a, min1);
	pb(stack_a, stack_b);
	min2 = find_min(*stack_a);
	bring_min_to_top(stack_a, min2);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	min;

	sort_three(stack_a);
	while (*stack_b)
	{
		set_position(stack_a);
		set_position(stack_b);
		set_target(stack_a, stack_b);
		costs(stack_a, stack_b);
		short_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
	{
		min = find_min(*stack_a);
		bring_min_to_top(stack_a, min);
	}
}
