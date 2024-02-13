/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:32:30 by ymatsui           #+#    #+#             */
/*   Updated: 2024/02/14 00:30:12 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int				i;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

void				push_swap(int argc, t_stack *stack_a, t_stack *stack_b);
void				ft_swap(int argc, t_stack *stack_a, t_stack *stack_b);
int					ft_print_rotate(int i);
int					ft_step_by_step_push(int i, t_stack *stack_a,
						t_stack *stack_b);

void				ft_swap_2(t_stack *stack_a);
void				ft_swap_3(t_stack *stack_a);
void				ft_swap_4(t_stack *stack_a, t_stack *stack_b);
void				ft_swap_5(t_stack *stack_a, t_stack *stack_b);
void				ft_swap_6(t_stack *stack_a, t_stack *stack_b);

t_stack				*ft_simple_push(t_stack *stack_a, t_stack *stack_b);
t_stack				*ft_double_push(t_stack *stack_a, t_stack *stack_b);
t_stack				*ft_final_push(t_stack *stack_a, t_stack *stack_b);
t_stack				*ft_push_a(t_stack *stack_a, t_stack *stack_b);
t_stack				*ft_push_b(t_stack *stack_a, t_stack *stack_b);

t_stack				*ft_rotate_a(t_stack *stack_a);
t_stack				*ft_reverse_rotate_a(t_stack *stack_a);
t_stack				*ft_rotate_b(t_stack *stack_b);
t_stack				*ft_reverse_rotate_b(t_stack *stack_b);

int					ft_atoi(const char *str, t_stack *stack_a);
int					ft_prep_stack(char **argv, t_stack *stack_a);

int					ft_check_stack(t_stack *stack_a, int tmp);
int					ft_connect_stack(t_stack *stack_a);
t_stack				*ft_free_stack(t_stack *stack_a);
t_stack				*ft_malloc_stack(void);
