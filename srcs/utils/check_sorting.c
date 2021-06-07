/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:30:02 by user42            #+#    #+#             */
/*   Updated: 2021/06/07 21:03:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_sorting(int *stack, int len)
{
	int	a;
	int	d;
	int	i;

	a = 1;
	d = 1;
	i = 0;
	while ((a == 1 || d == 1) && i < len - 1)
	{
		if (stack[i] < stack[i + 1])
			d = 0;
		else if (stack[i] > stack[i + 1])
			a = 0;
		i++;
	}
	if (a == 1)
		return (1);
	else if (d == 1)
		return (2);
	return (0);
}
