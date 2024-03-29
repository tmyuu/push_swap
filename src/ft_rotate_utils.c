/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:30:19 by ymatsui           #+#    #+#             */
/*   Updated: 2024/02/20 14:25:06 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_rotate_a(t_stack *stack_a)
{
	if (stack_a->prev == stack_a && stack_a->next == stack_a)
		return (stack_a);
	stack_a = stack_a->next;
	ft_printf("ra\n");
	return (stack_a);
}

t_stack	*ft_reverse_rotate_a(t_stack *stack_a)
{
	if (stack_a->prev == stack_a && stack_a->next == stack_a)
		return (stack_a);
	stack_a = stack_a->prev;
	ft_printf("rra\n");
	return (stack_a);
}

t_stack	*ft_rotate_b(t_stack *stack_b)
{
	if (stack_b->prev == stack_b && stack_b->next == stack_b)
		return (stack_b);
	stack_b = stack_b->next;
	ft_printf("rb\n");
	return (stack_b);
}

t_stack	*ft_reverse_rotate_b(t_stack *stack_b)
{
	if (stack_b->prev == stack_b && stack_b->next == stack_b)
		return (stack_b);
	stack_b = stack_b->prev;
	ft_printf("rrb\n");
	return (stack_b);
}
