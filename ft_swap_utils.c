/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:55:57 by ymatsui           #+#    #+#             */
/*   Updated: 2024/02/16 20:32:22 by ymatsui          ###   ########.fr       */
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

void	ft_final_swap(int argc, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	if (argc == 4)
	{
		stack_b = ft_final_rotate(stack_b);
		stack_a = stack_b;
		while (stack_b)
		{
			i++;
			stack_b = stack_b->next;
			if (stack_a->i == stack_b->i)
				break ;
		}
		while (i > 0)
		{
			printf("pa\n");
			i--;
		}
	}
}
