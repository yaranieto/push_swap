/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:36:06 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/07/04 11:56:29 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_b;
	int		target_pos;

	set_position(stack_a);
	set_position(stack_b);
	tmp_b = *stack_b;
	while (tmp_b)
	{
		target_pos = get_target(*stack_a, tmp_b->index);
		tmp_b->target = target_pos;
		tmp_b = tmp_b->next;
	}
}

void	set_position(t_list **stack)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

static int	find_min_position(t_list *stack_a)
{
	int		min_index;
	int		min_pos;
	t_list	*tmp;

	tmp = stack_a;
	min_index = INT_MAX;
	min_pos = 0;
	while (tmp)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			min_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (min_pos);
}

static int	find_target_position(t_list *stack_a, int stack_b_index)
{
	int		min_diff;
	int		target_pos;
	t_list	*tmp;

	min_diff = INT_MAX;
	target_pos = -1;
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->index > stack_b_index && (tmp->index - stack_b_index)
			< min_diff)
		{
			min_diff = tmp->index - stack_b_index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (target_pos);
}

int	get_target(t_list *stack_a, int stack_b_index)
{
	int	target_pos;

	target_pos = find_target_position(stack_a, stack_b_index);
	if (target_pos != -1)
		return (target_pos);
	return (find_min_position(stack_a));
}
