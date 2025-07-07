/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:28:52 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/07/04 12:22:46 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_list *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	find_min(t_list *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->data;
	while (stack)
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

int	get_position(t_list *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->data == value)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

void	bring_min_to_top(t_list **stack, int min)
{
	int		pos;
	int		size;
	t_list	*tmp;

	pos = get_position(*stack, min);
	size = 0;
	tmp = *stack;
	while (tmp && ++size)
		tmp = tmp->next;
	if (pos <= size / 2)
	{
		while ((*stack)->data != min)
			ra(stack);
	}
	else
	{
		while ((*stack)->data != min)
			rra(stack);
	}
}

void	index_stack(t_list *stack)
{
	t_list	*ptr1;
	t_list	*ptr2;
	int		index;

	ptr1 = stack;
	while (ptr1)
	{
		index = 0;
		ptr2 = stack;
		while (ptr2)
		{
			if (ptr2->data < ptr1->data)
				index++;
			ptr2 = ptr2->next;
		}
		ptr1->index = index;
		ptr1 = ptr1->next;
	}
}
