/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_prep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:31:39 by ymatsui           #+#    #+#             */
/*   Updated: 2024/02/20 13:01:41 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, t_stack *stack_a)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] == '-')
		{
			sign = -1;
			i++;
		}
		if (str[i] < '0' || str[i] > '9')
			return (0);
		if (stack_a->i > INT_MAX / 10)
			return (0);
		else if (sign == 1 && stack_a->i == INT_MAX / 10 && str[i] - '0' > 7)
			return (0);
		else if (sign == -1 && stack_a->i == INT_MAX / 10 && str[i] - '0' > 8)
			return (0);
		stack_a->i = stack_a->i * 10 + (str[i] - '0');
		i++;
	}
	stack_a->i = stack_a->i * sign;
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
		if (!ft_atoi(argv[i], stack_a))
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
		if (argv[i] == NULL)
			break ;
		stack_a->next = ft_malloc_stack();
		if (!stack_a->next)
			return (0);
		stack_a->next->prev = stack_a;
		stack_a = stack_a->next;
	}
	return (1);
}
