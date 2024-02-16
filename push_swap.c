/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:57:09 by ymatsui           #+#    #+#             */
/*   Updated: 2024/02/16 20:19:14 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int argc, t_stack *stack_a, t_stack *stack_b)
{
	int		rn;
	int		rrn;
	t_stack	*head;

	rn = ft_rotate_dfs(0, stack_a, stack_b);
	rrn = ft_reverse_rotate_dfs(0, stack_a, stack_b);
	if (ft_rotate_search_a(rn, stack_a,
			stack_b) < ft_reverse_rotate_search_a(rrn, stack_a, stack_b))
	{
		stack_a = ft_simple_rotate(1, rn, stack_a);
		head = stack_a->next;
		stack_b = ft_complex_rotate(1, rn, stack_a, stack_b);
	}
	else
	{
		stack_a = ft_simple_rotate(0, rrn, stack_a);
		head = stack_a->next;
		stack_b = ft_complex_rotate(0, rrn, stack_a, stack_b);
	}
	stack_b = ft_push_b(stack_a, stack_b);
	if (argc > 4)
		ft_swap(argc - 1, head, stack_b);
	else
		ft_final_swap(argc, head, stack_b);
}

void	push_swap(int argc, t_stack *stack_a, t_stack *stack_b)
{
	if (2 < argc && argc < 4)
		ft_swap_2(stack_a);
	else if (3 < argc && argc < 5)
		ft_swap_3(stack_a);
	else if (4 < argc && argc < 6)
		ft_swap_4(stack_a, stack_b);
	else if (5 < argc)
	{
		stack_b = stack_a;
		stack_a = ft_double_push(stack_a, stack_b);
		ft_swap(argc, stack_a, stack_b);
	}
}
