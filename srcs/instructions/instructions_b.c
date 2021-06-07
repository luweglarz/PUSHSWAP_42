/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:30:23 by user42            #+#    #+#             */
/*   Updated: 2021/06/07 21:00:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	do_sb(t_stack *stack)
{
	int	i;

	i = 2;
	if (stack->stack_b_len <= 1)
		return ;
	stack->tmp_stack_b = malloc(sizeof(int) * stack->stack_b_len);
	if (stack->tmp_stack_b == NULL)
		error(ERR_MALLOC, stack);
	stack->tmp_stack_b[1] = stack->stack_b[0];
	stack->tmp_stack_b[0] = stack->stack_b[1];
	while (i < stack->stack_b_len)
	{
		stack->tmp_stack_b[i] = stack->stack_b[i];
		i++;
	}
	free(stack->stack_b);
	stack->stack_b = NULL;
	stack->stack_b = ft_strdupint(stack->tmp_stack_b, stack->stack_b_len);
	free(stack->tmp_stack_b);
	stack->tmp_stack_b = NULL;
}

void	do_rb(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	stack->tmp_stack_b = malloc(sizeof(int) * stack->stack_b_len);
	if (stack->tmp_stack_b == NULL)
		error(ERR_MALLOC, stack);
	while (i < stack->stack_b_len - 1)
	{
		stack->tmp_stack_b[i] = stack->stack_b[j];
		j++;
		i++;
	}
	stack->tmp_stack_b[stack->stack_b_len - 1] = stack->stack_b[0];
	free(stack->stack_b);
	stack->stack_b = NULL;
	stack->stack_b = ft_strdupint(stack->tmp_stack_b, stack->stack_b_len);
	free(stack->tmp_stack_b);
	stack->tmp_stack_b = NULL;
}

void	do_rrb(t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (stack->stack_b_len <= 1)
		return ;
	stack->tmp_stack_b = malloc(sizeof(int) * stack->stack_b_len + 1);
	if (stack->tmp_stack_b == NULL)
		error(ERR_MALLOC, stack);
	stack->tmp_stack_b[0] = stack->stack_b[stack->stack_b_len - 1];
	while (i < stack->stack_b_len)
	{
		stack->tmp_stack_b[i] = stack->stack_b[j];
		j++;
		i++;
	}
	free(stack->stack_b);
	stack->stack_b = NULL;
	stack->stack_b = ft_strdupint(stack->tmp_stack_b, stack->stack_b_len);
	free(stack->tmp_stack_b);
	stack->tmp_stack_b = NULL;
}

void	do_pb(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (stack->stack_a_len <= 0)
		return ;
	stack->tmp_stack_b = malloc(sizeof(int) * ++stack->stack_b_len);
	stack->tmp_stack_a = malloc(sizeof(int) * --stack->stack_a_len);
	if (stack->tmp_stack_b == NULL || stack->tmp_stack_a == NULL)
		error(ERR_MALLOC, stack);
	stack->tmp_stack_b[0] = stack->stack_a[0];
	while (++i < stack->stack_a_len + 1)
	{
		stack->tmp_stack_a[j] = stack->stack_a[i];
		j++;
	}
	i = 0;
	j = 0;
	while (++i < stack->stack_b_len)
	{
		stack->tmp_stack_b[i] = stack->stack_b[j];
		j++;
	}
	put_in_stack(stack);
}
