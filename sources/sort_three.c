/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:19:04 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/30 12:53:20 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	first_cases(t_list **stack, int first, int second, int third);
static void	second_cases(t_list **stack, int first, int second, int third);

void	sort_three(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->content;
	second = (*stack)->next->content;
	third = (*stack)->next->next->content;
	if (!first_cases(stack, first, second, third))
		second_cases(stack, first, second, third);
}

static int	first_cases(t_list **stack, int first, int second, int third)
{
	if (first < second && third > first && second > third)
	{
		reverse_rotate(stack);
		swap(stack);
		ft_putendl_fd("rra\nsa", 1);
		return (1);
	}
	else if (first > second && third > first)
	{
		swap(stack);
		ft_putendl_fd("sa", 1);
		return (1);
	}
	else if (third < first && first < second)
	{
		reverse_rotate(stack);
		ft_putendl_fd("rra", 1);
		return (1);
	}
	return (0);
}

static void	second_cases(t_list **stack, int first, int second, int third)
{
	if (first > second && second < third)
	{
		rotate(stack);
		ft_putendl_fd("ra", 1);
	}
	else if (first > second && second > third)
	{
		rotate(stack);
		swap(stack);
		ft_putendl_fd("ra\nsa", 1);
	}
}

int	size_check(t_list **stack)
{
	if (size_of_stack(*stack) == 3)
	{
		sort_three(stack);
		free_list(stack);
		return (1);
	}
	return (0);
}
