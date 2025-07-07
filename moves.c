/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:36:52 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/07/05 11:12:36 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_negative(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	else
		return (nbr);
}

void	cheap_moves(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_both(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rot_both(stack_a, stack_b, &cost_a, &cost_b);
	rot_a(stack_a, &cost_a);
	rot_b(stack_b, &cost_b);
	pa(stack_a, stack_b);
}

void	push_init(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	while (size > 3)
	{
		pb(stack_a, stack_b);
		size--;
	}
}
