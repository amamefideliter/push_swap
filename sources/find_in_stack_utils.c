/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_stack_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:30:10 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/30 12:53:04 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_shift_for_max(t_list *stack);
static int	get_shift_for_min(t_list *stack);

int	find_position_in_b(t_list *stack_b, int number)
{
	int		shift;
	t_list	*lst;

	lst = stack_b;
	shift = 0;
	while (lst)
	{
		if (lst->next && number <= lst->content && number >= lst->next->content)
		{
			shift++;
			break ;
		}
		else if (!lst->next && number <= lst->content
			&& number >= stack_b->content)
		{
			shift = 0;
			break ;
		}
		shift++;
		lst = lst->next;
	}
	if (shift == size_of_stack(stack_b))
		shift = get_shift_for_max(stack_b);
	return (shift);
}

int	find_position_in_a(t_list *stack_a, int number)
{
	int		shift;
	t_list	*lst;

	lst = stack_a;
	shift = 0;
	while (lst)
	{
		if (lst->next && (number >= lst->content
				&& number <= lst->next->content))
		{
			shift++;
			break ;
		}
		else if (!lst->next && number >= lst->content
			&& number <= stack_a->content)
		{
			shift = 0;
			break ;
		}
		shift++;
		lst = lst->next;
	}
	if (shift == size_of_stack(stack_a))
		shift = get_shift_for_min(stack_a);
	return (shift);
}

static int	get_shift_for_min(t_list *stack)
{
	int		position;
	int		min_position;
	int		min_value;
	t_list	*tmp;

	min_value = INT_MAX;
	position = 0;
	min_position = position;
	tmp = stack;
	while (tmp)
	{
		if (tmp->content < min_value)
		{
			min_value = tmp->content;
			min_position = position;
		}
		position++;
		tmp = tmp->next;
	}
	return (min_position);
}

static int	get_shift_for_max(t_list *stack)
{
	int		position;
	int		max_position;
	int		max_value;
	t_list	*tmp;

	max_value = INT_MIN;
	position = 0;
	max_position = position;
	tmp = stack;
	while (tmp)
	{
		if (tmp->content > max_value)
		{
			max_value = tmp->content;
			max_position = position;
		}
		position++;
		tmp = tmp->next;
	}
	return (max_position);
}

int	find_min_moves(t_list *stack_a)
{
	int		min;
	int		shift;
	int		res;
	t_list	*copy;

	copy = stack_a;
	min = copy->moves;
	shift = 0;
	res = shift;
	while (copy)
	{
		if (copy->moves < min)
		{
			res = shift;
			min = copy->moves;
		}
		copy = copy->next;
		shift++;
	}
	return (res);
}
