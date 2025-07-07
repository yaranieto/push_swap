/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:23:33 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/07/04 14:12:53 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc > 1)
	{
		if (argc == 2)
			one_arg(&stack_a, argv);
		else
			stack_a = parse_args(argc, argv, 1);
		if (!stack_a)
			error_exit(&stack_a, NULL);
		stack_b = NULL;
		if (is_sorted(stack_a))
			return (free_stack(&stack_a), 0);
		push_swap(&stack_a, &stack_b, stack_size(stack_a));
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (0);
}

void	push_swap(t_list **stack_a, t_list **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		sort_two(stack_a);
	else if (stack_size == 3 && !is_sorted(*stack_a))
		sort_three(stack_a);
	else if (stack_size == 4 && !is_sorted(*stack_a))
		sort_four(stack_a, stack_b);
	else if (stack_size == 5 && !is_sorted(*stack_a))
		sort_five(stack_a, stack_b);
	else if (stack_size > 5 && !is_sorted(*stack_a))
	{
		index_stack(*stack_a);
		push_init(stack_a, stack_b);
		sort(stack_a, stack_b);
	}
}

void	one_arg(t_list **stack_a, char **argv)
{
	int		count;
	char	**split;

	count = 0;
	split = ft_split(argv[1], ' ');
	while (split[count])
		count ++;
	*stack_a = parse_args(count, split, 0);
	free_split(split);
}

void	free_split(char	**str)
{
	int	i;

	if (str != NULL)
	{
		i = 0;
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}
