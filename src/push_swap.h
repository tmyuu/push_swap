/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:32:30 by ymatsui           #+#    #+#             */
/*   Updated: 2024/02/20 14:30:22 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				i;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

void				push_swap(int argc, t_stack *stack_a, t_stack *stack_b);
void				ft_swap(int argc, t_stack *stack_a, t_stack *stack_b);
void				ft_final_swap_1(t_stack *stack_a, t_stack *stack_b);
void				ft_final_swap_2(t_stack *stack_a, t_stack *stack_b);

void				ft_initial_swap(t_stack *stack_a);
void				ft_direct_rotate_5_a(t_stack *stack_a);
void				ft_direct_reverse_rotate_5_a(t_stack *stack_a);
void				ft_direct_handling_5(t_stack *stack_a, t_stack *stack_b);
void				ft_direct_swap_5(t_stack *stack_a);

void				ft_swap_2(t_stack *stack_a);
void				ft_swap_3(t_stack *stack_a);
void				ft_swap_4(t_stack *stack_a);
void				ft_swap_5(t_stack *stack_a);
void				ft_swap_6(t_stack *stack_a);

int					ft_rotate_dfs(int n, t_stack *stack_a, t_stack *stack_b);
int					ft_reverse_rotate_dfs(int n, t_stack *stack_a,
						t_stack *stack_b);
int					ft_min_max_dfs(t_stack *stack_a, t_stack *stack_b);
int					ft_final_dfs(t_stack *stack_a);

int					ft_rotate_search_b(int max, int min, t_stack *stack_a,
						t_stack *stack_b);
int					ft_reverse_rotate_search_b(int max, int min,
						t_stack *stack_a, t_stack *stack_b);
int					ft_search_b(t_stack *stack_a, t_stack *stack_b);
int					ft_search(int n, t_stack *stack_a, t_stack *stack_b);
int					ft_r_search(int n, t_stack *stack_a, t_stack *stack_b);

void				ft_direct_rotate_3_a(t_stack *stack_a);
void				ft_direct_reverse_rotate_3_a(t_stack *stack_a);
void				ft_direct_swap_3(t_stack *stack_a);
void				ft_direct_rotate_4_a(t_stack *stack_a);
void				ft_direct_reverse_rotate_4_a(t_stack *stack_a);

t_stack				*ft_r_rotate(int i, int n, t_stack *stack_b);
t_stack				*ft_r_reverse_rotate(int i, int n, t_stack *stack_b);
t_stack				*ft_complex_rotate(int flag, int n, t_stack *stack_a,
						t_stack *stack_b);
t_stack				*ft_simple_rotate(int flag, int n, t_stack *stack_a);
void				ft_final_rotate(t_stack *stack_a, t_stack *stack_b);

t_stack				*ft_rotate_a(t_stack *stack_a);
t_stack				*ft_reverse_rotate_a(t_stack *stack_a);
t_stack				*ft_rotate_b(t_stack *stack_b);
t_stack				*ft_reverse_rotate_b(t_stack *stack_b);

t_stack				*ft_simple_push(t_stack *stack_a, t_stack *stack_b);
t_stack				*ft_double_push(t_stack *stack_a, t_stack *stack_b);
t_stack				*ft_push_a(t_stack *stack_a, t_stack *stack_b);
t_stack				*ft_push_b(t_stack *stack_a, t_stack *stack_b);

int					ft_atoi(const char *str, t_stack *stack_a);
int					ft_prep_stack(char **argv, t_stack *stack_a);

int					ft_check_stack(t_stack *stack_a, int tmp);
int					ft_connect_stack(t_stack *stack_a);
t_stack				*ft_free_stack(t_stack *stack_a);
t_stack				*ft_malloc_stack(void);

#endif