/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:50:33 by ymatsui           #+#    #+#             */
/*   Updated: 2024/02/20 21:15:24 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		stack_a = ft_malloc_stack();
		if (ft_prep_stack(argv + 1, stack_a))
			if (ft_connect_stack(stack_a))
				push_swap(stack_a, stack_b);
		stack_a = ft_free_stack(stack_a);
	}
	return (0);
}
