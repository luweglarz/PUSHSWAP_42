/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:09:06 by user42            #+#    #+#             */
/*   Updated: 2021/06/07 21:37:41 by user42           ###   ########.fr       */
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

void	do_instruction1(t_stack *stack, char *str)
{
	int	size;

	size = ft_strlen(str);
	if (size == 3)
	{
		if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		{
			write(1, "rra", 3);
			do_rra(stack);
		}
		if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		{
			write(1, "rrb", 3);
			do_rrb(stack);
		}
	}
	write (1, "\n", 1);
}

void	do_instruction2(t_stack *stack, char *str)
{
	int	size;

	size = ft_strlen(str);
	if (size == 2)
	{
		if (str[0] == 'r' && str[1] == 'a')
		{
			write(1, "ra", 2);
			do_ra(stack);
		}
		if (str[0] == 'p' && str[1] == 'a')
		{
			write(1, "pa", 2);
			do_pa(stack);
		}
		if (str[0] == 'p' && str[1] == 'b')
		{
			write(1, "pb", 2);
			do_pb(stack);
		}		
		if (str[0] == 's' && str[1] == 'b')
		{
			write(1, "sb", 2);
			do_sb(stack);
		}
		if (str[0] == 's' && str[1] == 'a')
		{
			write(1, "sa", 2);
			do_sa(stack);
		}
	}
	write (1, "\n", 1);
}
