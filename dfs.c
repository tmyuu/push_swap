/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:02:51 by ymatsui           #+#    #+#             */
/*   Updated: 2024/02/20 12:21:06 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate_dfs(int n, t_stack *stack_a, t_stack *stack_b)
{
	int			i;
	int			j;
	static int	count = 0;

	i = ft_search(n, stack_a, stack_b);
	if (i < 0)
		return (n);
	else if (n == 0)
		count = i;
	else if (count > i)
		count = i;
	j = ft_rotate_dfs(n + 1, stack_a, stack_b);
	if (count == i)
		j = n;
	return (j);
}

int	ft_reverse_rotate_dfs(int n, t_stack *stack_a, t_stack *stack_b)
{
	int			i;
	int			j;
	static int	count = 0;

	i = ft_r_search(n, stack_a, stack_b);
	if (i < 0)
		return (n);
	else if (n == 0)
		count = i;
	else if (count > i)
		count = i;
	j = ft_reverse_rotate_dfs(n + 1, stack_a, stack_b);
	if (count == i)
		j = n;
	return (j);
}

int	ft_min_max_dfs(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		j;
	t_stack	*head;

	i = 0;
	j = 0;
	head = stack_a;
	while (stack_a)
	{
		if (stack_a->i < stack_b->i)
			i++;
		j++;
		stack_a = stack_a->next;
		if (stack_a == head)
			break ;
	}
	if (i == 0 || i == j)
		return (-1);
	return (0);
}

int	ft_final_dfs(t_stack *stack_a)
{
	int		i;
	t_stack	*head;

	i = 0;
	head = stack_a;
	while (stack_a->i > stack_a->prev->i)
	{
		stack_a = stack_a->next;
		i++;
	}
	stack_a = head;
	while (stack_a->i > stack_a->prev->i)
	{
		stack_a = stack_a->prev;
		i--;
	}
	if (i > 0)
		i = -1;
	else
		i = 1;
	return (i);
}
