/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:36:14 by ymatsui           #+#    #+#             */
/*   Updated: 2024/02/20 14:25:58 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate_search_b(int max, int min, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (stack_b)
	{
		if (stack_a->i > stack_b->i && stack_a->i < stack_b->prev->i)
			break ;
		if (stack_b->i > stack_b->prev->i)
			if (stack_a->i > max || stack_a->i < min)
				break ;
		stack_b = stack_b->next;
		i++;
	}
	return (i);
}

int	ft_reverse_rotate_search_b(int max, int min, t_stack *stack_a,
		t_stack *stack_b)
{
	int	i;

	i = 0;
	while (stack_b)
	{
		if (stack_a->i > stack_b->i && stack_a->i < stack_b->prev->i)
			break ;
		if (stack_b->i > stack_b->prev->i)
			if (stack_a->i > max || stack_a->i < min)
				break ;
		stack_b = stack_b->prev;
		i--;
	}
	return (i);
}

int	ft_search_b(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		j;
	int		max;
	int		min;
	t_stack	*head;

	head = stack_b;
	while (stack_b->i < stack_b->prev->i)
		stack_b = stack_b->next;
	max = stack_b->i;
	min = stack_b->prev->i;
	stack_b = head;
	i = ft_rotate_search_b(max, min, stack_a, stack_b);
	j = ft_reverse_rotate_search_b(max, min, stack_a, stack_b);
	if (j < 0)
		if (i < -j)
			return (i);
	return (j);
}

int	ft_search(int n, t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*head;

	i = 0;
	head = stack_a;
	while (i < n)
	{
		stack_a = stack_a->next;
		if (stack_a->i == head->i)
			return (-1);
		i++;
	}
	i = ft_search_b(stack_a, stack_b);
	if (i < 0)
		i = -i + n;
	else if (n > i)
		return (n);
	return (i);
}

int	ft_r_search(int n, t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*head;

	i = 0;
	head = stack_a;
	while (i < n)
	{
		stack_a = stack_a->prev;
		if (stack_a->i == head->i)
			return (-1);
		i++;
	}
	i = ft_search_b(stack_a, stack_b);
	if (i < 0)
	{
		i = -i;
		if (n > i)
			return (n);
	}
	else
		i = i + n;
	return (i);
}
