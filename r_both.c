/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_both.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:23:28 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/07/04 11:58:40 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_a(stack_a);
	reverse_b(stack_b);
	write(1, "rrr\n", 4);
}

void	rev_both(t_list **stack_a, t_list **stack_b, int *cost_a,
	int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(stack_a, stack_b);
	}
}

void	rot_both(t_list **stack_a, t_list **stack_b, int *cost_a,
	int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(stack_a, stack_b);
	}
}
