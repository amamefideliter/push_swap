/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:52:16 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/30 12:53:15 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !(*stack))
		return ;
	ft_lstadd_back(stack, ft_lstnew((*stack)->content));
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

void	rotate_two(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	reverse_rotate(t_list **stack)
{
	if (!stack || !(*stack))
		return ;
	ft_lstadd_front(stack, ft_lstnew(ft_lstlast(*stack)->content));
	ft_lstdrop_back(stack);
}

void	reverse_rotate_two(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
