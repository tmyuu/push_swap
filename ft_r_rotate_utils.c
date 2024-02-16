/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_rotate_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:46:40 by ymatsui           #+#    #+#             */
/*   Updated: 2024/02/16 20:19:57 by ymatsui          ###   ########.fr       */
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
				printf("rr\n");
				i--;
			}
			else
				printf("ra\n");
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
				printf("rrr\n");
				i++;
			}
			else
				printf("rra\n");
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

t_stack	*ft_final_rotate(t_stack *stack_b)
{
	int		i;
	int		j;
	t_stack	*head;

	i = 0;
	head = stack_b;
	while (stack_b->i < stack_b->prev->i)
	{
		stack_b = stack_b->next;
		i++;
	}
	j = 0;
	stack_b = head;
	while (stack_b->i < stack_b->prev->i)
	{
		stack_b = stack_b->prev;
		i++;
	}
	if (i < j)
		while (head->i < head->prev->i)
			head = ft_rotate_b(head);
	else
		while (head->i < head->prev->i)
			head = ft_reverse_rotate_b(head);
	return (head);
}
