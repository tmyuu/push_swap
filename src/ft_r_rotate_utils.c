/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_rotate_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:46:40 by ymatsui           #+#    #+#             */
/*   Updated: 2024/02/20 14:25:04 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_r_rotate(int i, int n, t_stack *stack_b)
{
	while (i > 0 || n > 0)
	{
		if (i > n)
		{
			stack_b = ft_rotate_b(stack_b);
			i--;
		}
		else
		{
			if (i > 0)
			{
				stack_b = stack_b->next;
				ft_printf("rr\n");
				i--;
			}
			else
				ft_printf("ra\n");
			n--;
		}
	}
	return (stack_b);
}

t_stack	*ft_r_reverse_rotate(int i, int n, t_stack *stack_b)
{
	while (i < 0 || n > 0)
	{
		if (-i > n)
		{
			stack_b = ft_reverse_rotate_b(stack_b);
			i++;
		}
		else
		{
			if (-i > 0)
			{
				stack_b = stack_b->prev;
				ft_printf("rrr\n");
				i++;
			}
			else
				ft_printf("rra\n");
			n--;
		}
	}
	return (stack_b);
}

t_stack	*ft_complex_rotate(int flag, int n, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = ft_search_b(stack_a, stack_b);
	if (flag == 1)
	{
		while (i < 0)
		{
			stack_b = ft_reverse_rotate_b(stack_b);
			i++;
		}
		stack_b = ft_r_rotate(i, n, stack_b);
	}
	else
	{
		while (i > 0)
		{
			stack_b = ft_rotate_b(stack_b);
			i--;
		}
		stack_b = ft_r_reverse_rotate(i, n, stack_b);
	}
	return (stack_b);
}

t_stack	*ft_simple_rotate(int flag, int n, t_stack *stack_a)
{
	while (n > 0)
	{
		if (flag == 1)
			stack_a = stack_a->next;
		else
			stack_a = stack_a->prev;
		n--;
	}
	return (stack_a);
}

void	ft_final_rotate(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	if (ft_final_dfs(stack_a) > 0)
		while (stack_a->i > stack_a->prev->i)
			stack_a = ft_rotate_a(stack_a);
	else
		while (stack_a->i > stack_a->prev->i)
			stack_a = ft_reverse_rotate_a(stack_a);
}
