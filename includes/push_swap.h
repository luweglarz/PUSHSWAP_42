/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:44:11 by user42            #+#    #+#             */
/*   Updated: 2021/07/28 22:51:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>

# define ERR_VALUE1 -1
# define ERR_VALUE2 -2
# define ERR_VALUE3 -3
# define ERR_ARG -4
# define ERR_MALLOC -5

typedef struct s_stack
{
	int			*stack_a;
	int			*stack_b;
	int			*tmp_stack_a;
	int			*tmp_stack_b;
	int			stack_a_len;
	int			stack_a_lowest;
	int			stack_a_highest;
	int			stack_b_len;
	int			stack_b_lowest;
	int			stack_b_highest;
	char		**av;
}					t_stack;

void				init_stack(t_stack *stack, char **av, int ac);
void				fill_stack(t_stack *stack);
void				put_in_stack(t_stack *stack);
void				error(int errcode, t_stack *stack);

void				do_instruction_rr(t_stack *stack, char *str);
void				do_instruction_r(t_stack *stack, char *str);
void				do_instruction_p(t_stack *stack, char *str);
void				do_instruction_s(t_stack *stack, char *str);

void				do_sa(t_stack *stack);
void				do_ra(t_stack *stack);
void				do_rra(t_stack *stack);
void				do_pa(t_stack *stack);

void				do_sb(t_stack *stack);
void				do_rb(t_stack *stack);
void				do_rrb(t_stack *stack);
void				do_pb(t_stack *stack);

void				do_ss(t_stack *stack);
void				do_rr(t_stack *stack);
void				do_rrr(t_stack *stack);

int					ft_isdigit(int c);
int					ft_strlen(char *str);
long				ft_atoi(const char *nptr, t_stack *stack);
int					*ft_strdupint(int *t, int len);

int					check_sorting(int *stack, int len);

int					has_higher(int pivot, t_stack *stack);
int					has_lower(int pivot, t_stack *stack);
int					find_median(t_stack stack);
int					find_lowest(int *stack, int len);
int					find_highest(int *stack, int len);

void				sort_stack_3(t_stack *stack);
void				sort_stack_5(t_stack *stack);
void				sort_long_stack(t_stack *stack);

#endif
