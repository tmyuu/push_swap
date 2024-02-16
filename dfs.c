/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:02:51 by ymatsui           #+#    #+#             */
/*   Updated: 2024/02/16 16:02:58 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate_dfs(int n, t_stack *stack_a, t_stack *stack_b)
{
	int			i;
	int			j;
	static int	count = 0;

	i = ft_rotate_search_a(n, stack_a, stack_b);
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

	i = ft_reverse_rotate_search_a(n, stack_a, stack_b);
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
