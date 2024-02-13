/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:58:25 by ymatsui           #+#    #+#             */
/*   Updated: 2024/02/14 01:12:34 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_simple_push(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == stack_b)
	{
		stack_a->prev->next = stack_a->next;
		stack_a->next->prev = stack_a->prev;
		printf("pb\n");
		return (stack_a->next);
	}
	stack_a->prev->next = stack_b;
	stack_b->prev = stack_a->prev;
	stack_a->prev = stack_b;
	stack_b->next = stack_a;
	printf("pa\n");
	return (stack_b);
}

t_stack	*ft_double_push(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*head;

	i = 0;
	head = stack_a->next->next;
	stack_a->prev->next = stack_a->next->next;
	stack_a->next->next->prev = stack_a->prev;
	stack_b->prev = stack_b->next;
	stack_b->next->next = stack_b;
	printf("pb\npb\n");
	if (stack_b->i < stack_b->next->i)
	{
		i = stack_b->i;
		stack_b->i = stack_b->next->i;
		stack_b->next->i = i;
	}
	else
		printf("rb\n");
	return (head);
}

t_stack	*ft_final_push(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*head;

	head = stack_b->next;
	while (stack_a->i < stack_b->i || stack_b->i < stack_a->prev->i)
		stack_a = ft_reverse_rotate_a(stack_a);
	while (stack_a->i > stack_b->i && stack_b->i > stack_a->prev->i)
		stack_a = ft_push_a(stack_a, stack_b);
	stack_b = head;
	if (stack_a->i != stack_b->i)
		ft_final_push(stack_a, head);
	else
	{
		while (stack_a->i > stack_a->prev->i)
			stack_a = ft_reverse_rotate_a(stack_a);
	}
	return (NULL);
}

t_stack	*ft_push_a(t_stack *stack_a, t_stack *stack_b)
{
	stack_b->next->prev = stack_b->prev;
	stack_b->prev->next = stack_b->next;
	stack_a->prev->next = stack_b;
	stack_b->prev = stack_a->prev;
	stack_a->prev = stack_b;
	stack_b->next = stack_a;
	printf("pa\n");
	return (stack_b);
}

t_stack	*ft_push_b(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->next->prev = stack_a->prev;
	stack_a->prev->next = stack_a->next;
	stack_b->prev->next = stack_a;
	stack_a->prev = stack_b->prev;
	stack_b->prev = stack_a;
	stack_a->next = stack_b;
	printf("pb\n");
	return (stack_a);
}
