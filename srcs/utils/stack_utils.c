/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:09:06 by user42            #+#    #+#             */
/*   Updated: 2021/08/11 20:59:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	put_in_stack(t_stack *stack)
{
	free(stack->stack_a);
	stack->stack_a = NULL;
	stack->stack_a = ft_strdupint(stack->tmp_stack_a, stack->stack_a_len);
	free(stack->tmp_stack_a);
	stack->tmp_stack_a = NULL;
	if (stack->stack_b != NULL)
	{
		free(stack->stack_b);
		stack->stack_b = NULL;
	}
	stack->stack_b = ft_strdupint(stack->tmp_stack_b, stack->stack_b_len);
	free(stack->tmp_stack_b);
	stack->tmp_stack_b = NULL;
}

int	ft_count_arg(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		i++;
	i--;
	return (i);
}

void	init_stack(t_stack *stack, char **av, int ac)
{
	stack->stack_a = NULL;
	stack->av = av;
	if (ac < 2)
		error(ERR_ARG, stack);
	stack->stack_a_len = ft_count_arg(av);
	stack->stack_b = NULL;
	stack->stack_b_len = 0;
	stack->tmp_stack_a = NULL;
	stack->tmp_stack_b = NULL;
	stack->stack_a_highest = 0;
	stack->stack_b_highest = 0;
	stack->stack_a_lowest = 0;
	stack->stack_b_lowest = 0;
}
