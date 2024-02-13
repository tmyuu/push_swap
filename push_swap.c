/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:57:09 by ymatsui           #+#    #+#             */
/*   Updated: 2024/02/14 01:41:43 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_print_rotate(int i)
{
	while (i > 0)
	{
		printf("rb\n");
		i--;
	}
	while (i < 0)
	{
		printf("rrb\n");
		i++;
	}
	return (0);
}

int	ft_step_by_step_push(int i, t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->i > stack_b->i)
	{
		i = ft_print_rotate(i);
		stack_b = ft_push_b(stack_a, stack_b);
	}
	else if (stack_a->i < stack_b->prev->i)
	{
		i = ft_print_rotate(i);
		stack_b = ft_push_b(stack_a, stack_b);
		printf("rb\n");
	}
	else
	{
		while (stack_a->i < stack_b->i)
		{
			stack_b = stack_b->next;
			i++;
		}
		i = ft_print_rotate(i);
		stack_b = ft_push_b(stack_a, stack_b);
		while (stack_b->i < stack_b->prev->i)
		{
			stack_b = stack_b->prev;
			i--;
		}
	}
	return (i);
}

void	ft_swap(int argc, t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*head;

	i = 0;
	stack_b = stack_a;
	stack_a = ft_double_push(stack_a, stack_b);
	head = stack_a->next;
	while (argc > 6)
	{
		i = ft_step_by_step_push(i, stack_a, stack_b);
		stack_a = head;
		head = stack_a->next;
		if (stack_b->i < stack_b->prev->i)
			stack_b = stack_b->prev;
		argc--;
	}
	i = ft_print_rotate(i);
	ft_swap_6(stack_a, stack_b);
}

void	push_swap(int argc, t_stack *stack_a, t_stack *stack_b)
{
	if (2 < argc && argc < 4)
		ft_swap_2(stack_a);
	else if (3 < argc && argc < 5)
		ft_swap_3(stack_a);
	else if (4 < argc && argc < 6)
		ft_swap_4(stack_a, stack_b);
	else if (5 < argc && argc < 7)
		ft_swap_5(stack_a, stack_b);
	else
		ft_swap(argc, stack_a, stack_b);
}
