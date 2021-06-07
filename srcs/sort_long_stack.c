/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:35:17 by user42            #+#    #+#             */
/*   Updated: 2021/06/08 00:32:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	compt1(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack->stack_a_len)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			j++;
		i++;
	}
	return (j);
}

int	compt2(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack->stack_b_len)
	{
		if (stack->stack_b[i] < stack->stack_b[i + 1])
			j++;
		i++;
	}
	return (j);
}

void	split_stack(t_stack *stack)
{
	int	pivot;

	pivot = find_median(*stack);
	printf("pivot %d\n", pivot);
	while (has_lower(pivot, stack))
	{
		if (pivot >= stack->stack_a[0])
			do_pb(stack);
		else
			do_ra(stack);
	}
	stack->stack_a_lowest = find_lowest(stack->stack_a, stack->stack_a_len);
	stack->stack_b_lowest = find_lowest(stack->stack_b, stack->stack_b_len);
	stack->stack_a_highest = find_highest(stack->stack_a, stack->stack_a_len);
	stack->stack_b_highest = find_highest(stack->stack_b, stack->stack_b_len);
}

void	split_stack2(t_stack *stack)
{
	int	first_stack;
	int	second_stack;

	first_stack = compt1(stack);
	second_stack = compt2(stack);
	while (first_stack + 1 > second_stack)
	{
		do_instruction1(stack, "pb");
		first_stack = compt1(stack);
		second_stack = compt2(stack);
	}
}

void	sort_long_stack(t_stack *stack)
{
	while (check_sorting(stack->stack_a, stack->stack_a_len) != 1)
	{
		while (stack->stack_a[0] > stack->stack_a[stack->stack_a_len - 1])
			do_instruction2(stack, "rra");
		split_stack2(stack);
		while (stack->stack_b_len != 0)
		{
			if (stack->stack_b[0] < stack->stack_a[0] && stack->stack_b[0]
			> stack->stack_a[stack->stack_a_len - 1])
				do_instruction1(stack, "pa");
			else if (stack->stack_b[0] < stack->stack_a[0] && stack->stack_a[0]
			< stack->stack_a[stack->stack_a_len - 1])
				do_instruction1(stack, "pa");
			else if (stack->stack_b[0] > stack->stack_a[0] && stack->stack_a[0]
			< stack->stack_a[stack->stack_a_len - 1] && stack->stack_b[0]
			> stack->stack_a[stack->stack_a_len - 1])
				do_instruction1(stack, "pa");
			else
				do_instruction2(stack, "rra");
		}
		if (check_sorting(stack->stack_a, stack->stack_a_len) == 1)
			break ;
	}
}
