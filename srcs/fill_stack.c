/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:40:20 by user42            #+#    #+#             */
/*   Updated: 2021/05/14 17:54:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_duplicates(t_stack *stack)
{
	int		i;
	int		j;
	int		k;
	int		*tmptab;

	i = 0;
	j = 0;
	k = 0;
	tmptab = stack->stack_a;
	while (i < stack->stack_a_len)
	{
		k = 0;
		j = 0;
		while (j < stack->stack_a_len)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
				k++;
			if (k > 1)
				error(ERR_VALUE3, stack);
			j++;
		}
		i++;
	}
}

void	fill_stack(t_stack *stack)
{
	int		i;
	int		j;
	long	tmp_atoi;

	i = 1;
	j = 0;
	if (!(stack->stack_a = malloc(sizeof(int) * stack->stack_a_len)))
		error(ERR_MALLOC, stack);
	while (stack->av[i])
	{
		tmp_atoi = ft_atoi(stack->av[i], stack);
		if (tmp_atoi < -2147483648 || tmp_atoi > 2147483647)
			error(ERR_VALUE2, stack);
		stack->stack_a[j] = (int)tmp_atoi;
		j++;
		i++;
	}
	check_duplicates(stack);
}