/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:11:53 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/30 12:51:35 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

int		valid_integer(char *number);
int		is_sorted(int *array, int size);
int		max(int a, int b);
int		min(int a, int b);
int		abs_value(int number);
int		size_of_stack(t_list *stack);
int		size_check(t_list **stack);
int		find_position_in_a(t_list *stack_a, int number);
int		find_position_in_b(t_list *stack_b, int number);
int		find_min_moves(t_list *stack_a);
int		find_min_elem(t_list *stack_a);
void	make_moves(int cheapest, t_list **stack_a, t_list **stack_b);
void	push_back(t_list **stack_a, t_list **stack_b);
void	bring_element_on_top(t_list **stack_a, int rotation);
void	rotate(t_list **stack);
void	rotate_two(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **stack);
void	reverse_rotate_two(t_list **stack_a, t_list **stack_b);
void	push(t_list **stack_giver, t_list **stack_receiver);
void	swap_both(t_list **stack_a, t_list **stack_b);
void	swap(t_list **stack);
void	sort_stack(t_list **stack_a);
void	sort_three(t_list **stack);
void	free_list(t_list **stack);
t_list	*initialize_stack(int *array, int size);

#endif