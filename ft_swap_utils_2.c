/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:59:23 by ymatsui           #+#    #+#             */
/*   Updated: 2024/02/20 12:12:55 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_initial_swap(t_stack *stack_a)
{
	if (stack_a->i > stack_a->next->i && stack_a->next->i > stack_a->prev->i)
	{
		ft_direct_rotate_3_a(stack_a);
		ft_initial_swap(stack_a);
	}
	else if (stack_a->i < stack_a->next->i && stack_a->i < stack_a->prev->i)
	{
		ft_direct_reverse_rotate_3_a(stack_a);
		ft_initial_swap(stack_a);
	}
	else if (stack_a->i < stack_a->prev->i && stack_a->i > stack_a->next->i)
	{
		ft_direct_swap_3(stack_a);
		printf("sa\n");
	}
}

void	ft_direct_rotate_5_a(t_stack *stack_a)
{
	int	i;

	i = stack_a->i;
	stack_a->i = stack_a->next->i;
	stack_a->next->i = stack_a->next->next->i;
	stack_a->next->next->i = stack_a->prev->prev->i;
	stack_a->prev->prev->i = stack_a->prev->i;
	stack_a->prev->i = i;
	printf("ra\n");
}

void	ft_direct_reverse_rotate_5_a(t_stack *stack_a)
{
	int	i;

	i = stack_a->i;
	stack_a->i = stack_a->prev->i;
	stack_a->prev->i = stack_a->prev->prev->i;
	stack_a->prev->prev->i = stack_a->next->next->i;
	stack_a->next->next->i = stack_a->next->i;
	stack_a->next->i = i;
	printf("rra\n");
}

void	ft_direct_handling_5(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->next->i > stack_b->i)
	{
		ft_direct_rotate_4_a(stack_a);
		stack_a = ft_simple_push(stack_a, stack_b);
		ft_direct_reverse_rotate_5_a(stack_a);
	}
	else if (stack_a->next->next->i > stack_b->i)
	{
		ft_direct_rotate_4_a(stack_a);
		ft_direct_rotate_4_a(stack_a);
		stack_a = ft_simple_push(stack_a, stack_b);
		ft_direct_reverse_rotate_5_a(stack_a);
		ft_direct_reverse_rotate_5_a(stack_a);
	}
	else if (stack_a->prev->i > stack_b->i)
	{
		ft_direct_reverse_rotate_4_a(stack_a);
		stack_a = ft_simple_push(stack_a, stack_b);
		ft_direct_rotate_5_a(stack_a);
		ft_direct_rotate_5_a(stack_a);
	}
}

void	ft_direct_swap_5(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = stack_a;
	stack_a = ft_simple_push(stack_a, stack_b);
	ft_swap_4(stack_a);
	if (ft_min_max_dfs(stack_a, stack_b) < 0)
	{
		stack_a = ft_simple_push(stack_a, stack_b);
		if (stack_a->prev->i < stack_b->i)
			ft_direct_rotate_5_a(stack_a);
	}
	else
		ft_direct_handling_5(stack_a, stack_b);
}
