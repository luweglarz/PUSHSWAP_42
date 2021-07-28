/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 22:49:00 by user42            #+#    #+#             */
/*   Updated: 2021/07/28 22:54:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	do_instruction_rr(t_stack *stack, char *str)
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
	write (1, "\n", 1);
}

void	do_instruction_r(t_stack *stack, char *str)
{
	if (str[0] == 'r' && str[1] == 'a')
	{
		write(1, "ra", 2);
		do_ra(stack);
	}
	if (str[0] == 'r' && str[1] == 'b')
	{
		write(1, "rb", 2);
		do_ra(stack);
	}	
	write (1, "\n", 1);
}

void	do_instruction_p(t_stack *stack, char *str)
{
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
	write (1, "\n", 1);
}

void	do_instruction_s(t_stack *stack, char *str)
{
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
	write (1, "\n", 1);
}
