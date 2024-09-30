/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:21:50 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/30 12:53:18 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	find_cheapest(t_list **stack_a, t_list *stack_b);
static int	set_moves(t_list **current_node, int shift_a,
				int shift_b, int moves);
static void	get_moves(t_list **current_node_a, t_list *stack_b,
				int shift, int size_a);

void	sort_stack(t_list **stack_a)
{
	t_list	*stack_b;
	t_list	*copy;

	stack_b = NULL;
	while (size_of_stack(*stack_a) > 3)
	{
		if (size_of_stack(stack_b) < 2)
		{
			push(stack_a, &stack_b);
			ft_putstr_fd("pb\n", 1);
		}
		else
		{
			find_cheapest(stack_a, stack_b);
			copy = *stack_a;
			make_moves(find_min_moves(copy), stack_a, &stack_b);
		}
	}
	sort_three(stack_a);
	push_back(stack_a, &stack_b);
	bring_element_on_top(stack_a, find_min_elem(*stack_a));
	free_list(stack_a);
}

static void	find_cheapest(t_list **stack_a, t_list *stack_b)
{
	t_list	*lst;
	int		shift;
	int		size_a;

	lst = *stack_a;
	size_a = size_of_stack(*stack_a);
	shift = 0;
	while (lst)
	{
		get_moves(&lst, stack_b, shift, size_a);
		lst = lst->next;
		shift++;
	}
}

static void	get_moves(t_list **current_node_a, t_list *stack_b,
						int shift, int size_a)
{
	int	pos_b;
	int	reverse_pos_b;
	int	reverse_shift;
	int	moves_count;

	moves_count = INT_MAX;
	pos_b = find_position_in_b(stack_b, (*current_node_a)->content);
	reverse_shift = size_a - shift;
	reverse_pos_b = size_of_stack(stack_b) - pos_b;
	if (max(reverse_pos_b, reverse_shift) < moves_count)
		moves_count = set_moves(current_node_a, (-1 * reverse_shift),
				(-1 * reverse_pos_b), max(reverse_pos_b, reverse_shift));
	if (max(pos_b, shift) < moves_count)
		moves_count = set_moves(current_node_a, shift,
				pos_b, max(pos_b, shift));
	if (reverse_shift + pos_b < moves_count)
		moves_count = set_moves(current_node_a,
				(-1 * reverse_shift), pos_b, reverse_shift + pos_b);
	if (shift + reverse_pos_b < moves_count)
		moves_count = set_moves(current_node_a, shift,
				(-1 * reverse_pos_b), shift + reverse_pos_b);
}

static int	set_moves(t_list **current_node, int shift_a,
						int shift_b, int moves)
{
	if (shift_a > 0 && shift_b > 0)
	{
		(*current_node)->together = min(shift_a, shift_b);
		(*current_node)->shift_a = shift_a - min(shift_a, shift_b);
		(*current_node)->shift_b = shift_b - min(shift_a, shift_b);
	}
	else if (shift_a < 0 && shift_b < 0)
	{
		(*current_node)->together = max(shift_a, shift_b);
		(*current_node)->shift_a = shift_a - max(shift_a, shift_b);
		(*current_node)->shift_b = shift_b - max(shift_a, shift_b);
	}
	else
	{
		(*current_node)->together = 0;
		(*current_node)->shift_a = shift_a;
		(*current_node)->shift_b = shift_b;
	}
	(*current_node)->moves = moves;
	if ((shift_a < 0 && shift_b < 0) || (shift_a > 0 && shift_b > 0))
		return (max(abs_value(shift_a), abs_value(shift_b)));
	else
		return (abs_value(shift_a) + abs_value(shift_b));
}
