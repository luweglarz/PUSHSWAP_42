/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:30:24 by user42            #+#    #+#             */
/*   Updated: 2021/06/07 20:57:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	do_sa(t_stack *stack)
{
	int		i;

	i = 2;
	if (stack->stack_a_len <= 1)
		return ;
	stack->tmp_stack_a = malloc(sizeof(int) * stack->stack_a_len);
	if (stack->tmp_stack_a == NULL)
		error(ERR_MALLOC, stack);
	stack->tmp_stack_a[1] = stack->stack_a[0];
	stack->tmp_stack_a[0] = stack->stack_a[1];
	while (i < stack->stack_a_len)
	{
		stack->tmp_stack_a[i] = stack->stack_a[i];
		i++;
	}
	free(stack->stack_a);
	stack->stack_a = NULL;
	stack->stack_a = ft_strdupint(stack->tmp_stack_a, stack->stack_a_len);
	free(stack->tmp_stack_a);
	stack->tmp_stack_a = NULL;
}

void	do_ra(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	stack->tmp_stack_a = malloc(sizeof(int) * stack->stack_a_len);
	if (stack->tmp_stack_a == NULL)
		error(ERR_MALLOC, stack);
	while (i < stack->stack_a_len - 1)
	{
		stack->tmp_stack_a[i] = stack->stack_a[j];
		j++;
		i++;
	}
	stack->tmp_stack_a[stack->stack_a_len - 1] = stack->stack_a[0];
	free(stack->stack_a);
	stack->stack_a = NULL;
	stack->stack_a = ft_strdupint(stack->tmp_stack_a, stack->stack_a_len);
	free(stack->tmp_stack_a);
	stack->tmp_stack_a = NULL;
}

void	do_rra(t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	stack->tmp_stack_a = malloc(sizeof(int) * stack->stack_a_len);
	if (stack->tmp_stack_a == NULL)
		error(ERR_MALLOC, stack);
	stack->tmp_stack_a[0] = stack->stack_a[stack->stack_a_len - 1];
	while (i < stack->stack_a_len)
	{
		stack->tmp_stack_a[i] = stack->stack_a[j];
		j++;
		i++;
	}
	free(stack->stack_a);
	stack->stack_a = NULL;
	stack->stack_a = ft_strdupint(stack->tmp_stack_a, stack->stack_a_len);
	free(stack->tmp_stack_a);
	stack->tmp_stack_a = NULL;
}

void	do_pa(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (stack->stack_b_len <= 0)
		return ;
	stack->tmp_stack_a = malloc(sizeof(int) * ++stack->stack_a_len);
	stack->tmp_stack_b = malloc(sizeof(int) * --stack->stack_b_len);
	if (stack->tmp_stack_b == NULL || stack->tmp_stack_a == NULL)
		error(ERR_MALLOC, stack);
	stack->tmp_stack_a[0] = stack->stack_b[0];
	while (++i < stack->stack_b_len + 1)
	{
		stack->tmp_stack_b[j] = stack->stack_b[i];
		j++;
	}
	i = 0;
	j = 0;
	while (++i < stack->stack_a_len)
	{
		stack->tmp_stack_a[i] = stack->stack_a[j];
		j++;
	}
	put_in_stack(stack);
}
