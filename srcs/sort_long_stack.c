/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:35:17 by user42            #+#    #+#             */
/*   Updated: 2021/07/27 22:11:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include "../includes/push_swap.h"

int	nb_sup_a(t_stack *stack)
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

void	split_stack(t_stack *stack)
{
	int	nb_sup;

	nb_sup = nb_sup_a(stack);
	while (stack->stack_a[0] > stack->stack_a[stack->stack_a_len - 1])
 			do_instruction1(stack, "rra");
	if (check_sorting(stack->stack_a, stack->stack_a_len) == 1)
		return ;
	while (stack->stack_a_len != nb_sup)
		do_instruction2(stack, "pb");
}

void	sort_long_stack(t_stack *stack)
{
	while (check_sorting(stack->stack_a, stack->stack_a_len) != 1)
	{
		split_stack(stack);
		while (stack->stack_b_len != 0)
		{
			if (stack->stack_b[0] < stack->stack_a[0] && stack->stack_b[0]
			> stack->stack_a[stack->stack_a_len - 1])
				do_instruction2(stack, "pa");
			else if (stack->stack_b[0] < stack->stack_a[0] && stack->stack_a[0]
			< stack->stack_a[stack->stack_a_len - 1])
				do_instruction2(stack, "pa");
			else if (stack->stack_b[0] > stack->stack_a[0] && stack->stack_a[0]
			< stack->stack_a[stack->stack_a_len - 1] && stack->stack_b[0]
			> stack->stack_a[stack->stack_a_len - 1])
				do_instruction2(stack, "pa"); 
			else
				do_instruction1(stack, "rra");
		}
		if (check_sorting(stack->stack_a, stack->stack_a_len) == 1)
			break ;
	}
}

