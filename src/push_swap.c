/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:57:09 by ymatsui           #+#    #+#             */
/*   Updated: 2024/02/20 21:24:57 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_final_swap_2(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*head;

	if (stack_a->i > stack_a->prev->i && stack_a->prev->i < stack_b->prev->i)
		while (stack_a->i > stack_a->prev->i)
			stack_a = ft_reverse_rotate_a(stack_a);
	if (stack_a->prev->i > stack_b->i)
		stack_a = ft_reverse_rotate_a(stack_a);
	while (stack_b)
	{
		head = stack_b->next;
		if (stack_a->prev->i > stack_b->i && stack_a->prev->i < stack_a->i)
			stack_a = ft_reverse_rotate_a(stack_a);
		else
		{
			stack_a = ft_push_a(stack_a, stack_b);
			stack_b = head;
		}
		if (stack_a == head)
			stack_b = NULL;
	}
	ft_final_rotate(stack_a, stack_b);
}

void	ft_final_swap_1(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*head;

	while (stack_b->i < stack_b->prev->i)
	{
		head = stack_b->next;
		if (ft_min_max_dfs(stack_a, stack_b) < 0)
		{
			if (stack_a->i > stack_a->prev->i)
				stack_a = ft_reverse_rotate_a(stack_a);
			else
			{
				stack_a = ft_push_a(stack_a, stack_b);
				stack_b = head;
			}
		}
		else if (stack_b->i < stack_a->prev->i)
			stack_a = ft_reverse_rotate_a(stack_a);
		else
		{
			stack_a = ft_push_a(stack_a, stack_b);
			stack_b = head;
		}
	}
	ft_final_swap_2(stack_a, stack_b);
}

void	ft_swap(int argc, t_stack *stack_a, t_stack *stack_b)
{
	int		n;
	int		rn;
	int		i;
	t_stack	*head;

	i = 0;
	n = ft_rotate_dfs(i, stack_a, stack_b);
	rn = ft_reverse_rotate_dfs(i, stack_a, stack_b);
	if (ft_search(n, stack_a, stack_b) < ft_r_search(rn, stack_a, stack_b))
		i = 1;
	if (i < 1)
		n = rn;
	stack_a = ft_simple_rotate(i, n, stack_a);
	head = stack_a->next;
	stack_b = ft_complex_rotate(i, n, stack_a, stack_b);
	stack_b = ft_push_b(stack_a, stack_b);
	if (argc > 9)
		ft_swap(argc - 1, head, stack_b);
	else
	{
		ft_direct_swap_5(head);
		ft_final_swap_1(head, stack_b);
	}
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	argc;

	argc = ft_argc(stack_a) + 1;
	if (2 < argc && argc < 4)
		ft_swap_2(stack_a);
	else if (3 < argc && argc < 5)
		ft_swap_3(stack_a);
	else if (4 < argc && argc < 6)
		ft_swap_4(stack_a);
	else if (5 < argc && argc < 7)
		ft_swap_5(stack_a);
	else if (6 < argc && argc < 8)
		ft_swap_6(stack_a);
	else if (7 < argc)
	{
		stack_b = stack_a;
		stack_a = ft_double_push(stack_a, stack_b);
		if (argc < 9)
		{
			ft_direct_swap_5(stack_a);
			ft_final_swap_1(stack_a, stack_b);
		}
		else
			ft_swap(argc, stack_a, stack_b);
	}
}
