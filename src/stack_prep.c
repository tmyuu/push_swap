/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_prep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:31:39 by ymatsui           #+#    #+#             */
/*   Updated: 2024/02/20 21:39:14 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_argc(t_stack *stack_a)
{
	int		i;
	int		j;
	t_stack	*head;

	i = 0;
	j = 0;
	head = stack_a;
	while (stack_a)
	{
		stack_a = stack_a->next;
		i++;
		if (stack_a == head)
			break ;
		else if (stack_a->prev->i > stack_a->i)
			j++;
	}
	if (j == 0)
		return (j);
	return (i);
}

int	ft_atoi_util(int i, int sign, const char *str, t_stack *stack_a)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (stack_a->i > INT_MAX / 10)
			return (0);
		else if (sign == 1 && stack_a->i == INT_MAX / 10 && str[i] - '0' > 7)
			return (0);
		else if (sign == -1 && stack_a->i == INT_MAX / 10 && str[i] - '0' > 8)
			return (0);
		stack_a->i = stack_a->i * 10 + (str[i] - '0');
		i++;
	}
	return (i);
}

int	ft_just_while(int i, const char *str)
{
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	ft_atoi(const char *str, t_stack *stack_a)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str)
	{
		i = ft_just_while(i, str);
		if (str[i] == '-')
		{
			sign = -1;
			i++;
		}
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i = ft_atoi_util(i, sign, str, stack_a);
		stack_a->i = stack_a->i * sign;
		i = ft_just_while(i, str);
		if (str[i] == '\0')
			break ;
		stack_a = ft_malloc_next_stack(stack_a);
		if (!stack_a)
			return (0);
	}
	return (i);
}

int	ft_prep_stack(char **argv, t_stack *stack_a)
{
	int	i;

	i = 0;
	if (!stack_a)
		return (0);
	while (argv[i] != NULL)
	{
		if (ft_atoi(argv[i], stack_a))
		{
			i++;
			while (stack_a->next)
				stack_a = stack_a->next;
			if (argv[i] == NULL)
				break ;
			stack_a = ft_malloc_next_stack(stack_a);
			if (!stack_a)
				return (0);
		}
		else
		{
			ft_printf("Error\n");
			return (0);
		}
	}
	return (1);
}
