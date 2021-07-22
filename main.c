/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:46:42 by user42            #+#    #+#             */
/*   Updated: 2021/06/07 21:06:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int main(int ac, char **av)
{
	t_stack	stack;

	init_stack(&stack, av, ac);
	fill_stack(&stack);

	if (check_sorting(stack.stack_a, stack.stack_a_len) == 1)
	{
		free(stack.stack_a);
		return (0);
	}
	if (stack.stack_a_len == 2)
		do_sa(&stack);
	if (stack.stack_a_len == 3)
		sort_stack_3(&stack);
	if (stack.stack_a_len == 5 || stack.stack_a_len == 4)
	{
		sort_stack_5(&stack);
		while (stack.stack_b_len)
			do_instruction2(&stack ,"pa");
		free(stack.stack_b);
	}
	if (stack.stack_a_len > 5)
		sort_long_stack(&stack);
	free(stack.stack_a);
}
