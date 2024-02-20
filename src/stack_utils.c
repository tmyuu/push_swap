/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:40:16 by ymatsui           #+#    #+#             */
/*   Updated: 2024/02/20 14:25:29 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_stack(t_stack *stack_a, int i)
{
	while (stack_a->next)
	{
		stack_a = stack_a->next;
		if (stack_a->i == i)
			return (0);
	}
	return (1);
}

int	ft_connect_stack(t_stack *stack_a)
{
	int		i;
	t_stack	*head;

	i = 0;
	head = stack_a;
	while (stack_a->next)
	{
		i = stack_a->i;
		if (!ft_check_stack(stack_a, i))
		{
			ft_printf("Error\n");
			return (0);
		}
		stack_a = stack_a->next;
	}
	stack_a->next = head;
	head->prev = stack_a;
	return (1);
}

t_stack	*ft_free_stack(t_stack *stack_a)
{
	t_stack	*tmp;

	if (!stack_a)
		return (NULL);
	if (stack_a->prev)
		stack_a->prev->next = NULL;
	if (!stack_a->next)
		free(stack_a);
	else
	{
		while (stack_a->next)
		{
			tmp = stack_a->next;
			free(stack_a);
			stack_a = tmp;
		}
	}
	return (NULL);
}

t_stack	*ft_malloc_stack(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->i = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
