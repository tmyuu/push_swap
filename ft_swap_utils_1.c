/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:55:57 by ymatsui           #+#    #+#             */
/*   Updated: 2024/02/20 12:21:22 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_2(t_stack *stack_a)
{
	if (stack_a->i > stack_a->next->i)
		ft_direct_rotate_3_a(stack_a);
}

void	ft_swap_3(t_stack *stack_a)
{
	if (stack_a->i < stack_a->next->i && stack_a->next->i < stack_a->prev->i)
		;
	else
		ft_initial_swap(stack_a);
	if (stack_a->i > stack_a->prev->i && stack_a->next->i < stack_a->prev->i)
		ft_direct_rotate_3_a(stack_a);
	else if (stack_a->i > stack_a->prev->i && stack_a->i < stack_a->next->i)
		ft_direct_reverse_rotate_3_a(stack_a);
}

void	ft_swap_4(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = stack_a;
	stack_a = ft_simple_push(stack_a, stack_b);
	ft_swap_3(stack_a);
	if (ft_min_max_dfs(stack_a, stack_b) < 0)
	{
		stack_a = ft_simple_push(stack_a, stack_b);
		if (stack_a->prev->i < stack_b->i)
			ft_direct_rotate_4_a(stack_a);
	}
	else
	{
		if (stack_a->next->i > stack_b->i)
			ft_direct_rotate_3_a(stack_a);
		else
			ft_direct_reverse_rotate_3_a(stack_a);
		stack_a = ft_simple_push(stack_a, stack_b);
		ft_direct_reverse_rotate_4_a(stack_a);
		if (stack_a->i > stack_a->prev->i)
			ft_direct_reverse_rotate_4_a(stack_a);
	}
}

void	ft_swap_5(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = stack_a;
	stack_a = ft_double_push(stack_a, stack_a);
	ft_swap_3(stack_a);
	if (stack_b->i < stack_b->next->i)
	{
		ft_direct_swap_3(stack_b);
		printf("sb\n");
	}
	ft_final_swap_1(stack_a, stack_b);
}

void	ft_swap_6(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = stack_a;
	stack_a = ft_double_push(stack_a, stack_a);
	ft_swap_4(stack_a);
	if (stack_b->i < stack_b->next->i)
	{
		ft_direct_swap_3(stack_b);
		printf("sb\n");
	}
	ft_final_swap_1(stack_a, stack_b);
}
