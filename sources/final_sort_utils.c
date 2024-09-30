/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:41:24 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/30 12:52:56 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bring_element_on_top(t_list **stack_a, int rotation)
{
	if (rotation > size_of_stack(*stack_a) / 2)
		rotation = (size_of_stack(*stack_a) - rotation) * -1;
	if (rotation > 0)
	{
		while (rotation--)
		{
			rotate(stack_a);
			ft_putstr_fd("ra\n", 1);
		}
	}
	else if (rotation < 0)
	{
		while (rotation++)
		{
			reverse_rotate(stack_a);
			ft_putstr_fd("rra\n", 1);
		}
	}
}

int	find_min_elem(t_list *stack_a)
{
	int		min;
	int		shift;
	int		res;
	t_list	*copy;

	min = stack_a->content;
	copy = stack_a;
	shift = 0;
	res = shift;
	while (copy)
	{
		if (copy->content < min)
		{
			res = shift;
			min = copy->content;
		}
		shift++;
		copy = copy->next;
	}
	return (res);
}
