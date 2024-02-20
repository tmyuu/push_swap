/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:09:29 by ymatsui           #+#    #+#             */
/*   Updated: 2024/02/20 12:11:37 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_direct_rotate_3_a(t_stack *stack_a)
{
	int	i;

	i = stack_a->i;
	stack_a->i = stack_a->next->i;
	stack_a->next->i = stack_a->prev->i;
	stack_a->prev->i = i;
	printf("ra\n");
}

void	ft_direct_reverse_rotate_3_a(t_stack *stack_a)
{
	int	i;

	i = stack_a->i;
	stack_a->i = stack_a->prev->i;
	stack_a->prev->i = stack_a->next->i;
	stack_a->next->i = i;
	printf("rra\n");
}

void	ft_direct_swap_3(t_stack *stack)
{
	int	i;

	i = stack->i;
	stack->i = stack->next->i;
	stack->next->i = i;
}

void	ft_direct_rotate_4_a(t_stack *stack_a)
{
	int	i;

	i = stack_a->i;
	stack_a->i = stack_a->next->i;
	stack_a->next->i = stack_a->next->next->i;
	stack_a->next->next->i = stack_a->prev->i;
	stack_a->prev->i = i;
	printf("ra\n");
}

void	ft_direct_reverse_rotate_4_a(t_stack *stack_a)
{
	int	i;

	i = stack_a->i;
	stack_a->i = stack_a->prev->i;
	stack_a->prev->i = stack_a->prev->prev->i;
	stack_a->prev->prev->i = stack_a->next->i;
	stack_a->next->i = i;
	printf("rra\n");
}
