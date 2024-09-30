/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:11:53 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/30 12:53:22 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list **stack)
{
	int	tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = ((*stack)->next)->content;
	((*stack)->next)->content = tmp;
}

void	swap_both(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	push(t_list **stack_giver, t_list **stack_receiver)
{
	t_list	*tmp;

	if (!stack_giver || !(*stack_giver))
		return ;
	ft_lstadd_front(stack_receiver, ft_lstnew((*stack_giver)->content));
	tmp = *stack_giver;
	*stack_giver = (*stack_giver)->next;
	free(tmp);
}
