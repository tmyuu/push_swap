/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:55:57 by ymatsui           #+#    #+#             */
/*   Updated: 2024/02/14 00:49:33 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_2(t_stack *stack_a)
{
	int	i;

	i = 0;
	if (stack_a->i > stack_a->next->i)
	{
		i = stack_a->i;
		stack_a->i = stack_a->next->i;
		stack_a->next->i = i;
		printf("ra\n");
	}
}

void	ft_swap_3(t_stack *stack_a)
{
	int	i;

	i = 0;
	// else if = 213, else = 132, 231, 312, 321
	if (stack_a->i < stack_a->next->i && stack_a->next->i < stack_a->prev->i)
		return ;
	else if (stack_a->i < stack_a->prev->i && stack_a->i > stack_a->next->i)
	{
		i = stack_a->i;
		stack_a->i = stack_a->next->i;
		stack_a->next->i = i;
		printf("sa\n");
		ft_swap_3(stack_a);
	}
	else
	{
		i = stack_a->i;
		stack_a->i = stack_a->next->i;
		stack_a->next->i = stack_a->prev->i;
		stack_a->prev->i = i;
		printf("ra\n");
		ft_swap_3(stack_a);
	}
}

void	ft_swap_4(t_stack *stack_a, t_stack *stack_b)
{
	stack_b = stack_a;
	stack_a = ft_simple_push(stack_a, stack_b);
	ft_swap_3(stack_a);
	if (stack_a->prev->i < stack_b->i)
	{
		stack_a = ft_simple_push(stack_a, stack_b);
		stack_b = NULL;
		stack_a = ft_rotate_a(stack_a);
	}
	else
	{
		while (stack_a->i < stack_b->i)
			stack_a = ft_rotate_a(stack_a);
		if (stack_a->i > stack_b->i)
		{
			stack_a = ft_simple_push(stack_a, stack_b);
			stack_b = NULL;
		}
		while (stack_a->i > stack_a->prev->i)
			stack_a = ft_reverse_rotate_a(stack_a);
	}
}

void	ft_swap_5(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*head;

	stack_b = stack_a;
	stack_a = ft_double_push(stack_a, stack_b);
	ft_swap_3(stack_a);
	head = stack_b;
	if (stack_a->i > stack_b->prev->i)
	{
		stack_b = ft_reverse_rotate_b(stack_b);
		head = stack_b->next;
		stack_a = ft_push_a(stack_a, stack_b);
		stack_b = head;
	}
	if (stack_a->prev->i < stack_b->i)
	{
		head = stack_b->next;
		stack_a = ft_push_a(stack_a, stack_b);
		stack_b = head;
		stack_a = ft_rotate_a(stack_a);
	}
	stack_b = head;
	stack_b = ft_final_push(stack_a, stack_b);
}

void	ft_swap_6(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*head;

	ft_swap_3(stack_a);
	head = stack_b;
	if (stack_a->i > stack_b->prev->i)
	{
		stack_b = ft_reverse_rotate_b(stack_b);
		head = stack_b->next;
		stack_a = ft_push_a(stack_a, stack_b);
		stack_b = head;
	}
	if (stack_a->prev->i < stack_b->i)
	{
		head = stack_b->next;
		stack_a = ft_push_a(stack_a, stack_b);
		stack_b = head;
		stack_a = ft_rotate_a(stack_a);
	}
	stack_b = head;
	stack_b = ft_final_push(stack_a, stack_b);
}
