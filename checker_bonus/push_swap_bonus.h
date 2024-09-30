/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:11:53 by dzubkova          #+#    #+#             */
/*   Updated: 2024/02/16 15:02:16 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "./get_next_line/get_next_line.h"
# include "../push_swap.h"
# include "../libft/libft.h"

int		read_commands(t_list **stack_a, t_list **stack_b);
int		is_sorted_stack(t_list *stack);
void	terminate_stacks(t_list *stack_a, t_list *stack_b);

#endif