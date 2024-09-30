/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:45:11 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/30 12:53:12 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	make_moves_together(t_list **stack_a,
				t_list **stack_b, int together);
static void	make_moves_stack_a(t_list **stack_a, int shift_a);
static void	make_moves_stack_b(t_list **stack_b, int shift_b);

void	make_moves(int cheapest, t_list **stack_a, t_list **stack_b)
{
	t_list	*copy;
	int		together;
	int		shift_a;
	int		shift_b;

	copy = *stack_a;
	while (cheapest--)
		copy = copy->next;
	together = copy->together;
	shift_a = copy->shift_a;
	shift_b = copy->shift_b;
	make_moves_together(stack_a, stack_b, together);
	make_moves_stack_a(stack_a, shift_a);
	make_moves_stack_b(stack_b, shift_b);
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}

static void	make_moves_together(t_list **stack_a,
			t_list **stack_b, int together)
{
	if (together > 0)
	{
		while (together--)
		{
			rotate_two(stack_a, stack_b);
			ft_putstr_fd("rr\n", 1);
		}
	}
	else if (together < 0)
	{
		while (together++)
		{
			reverse_rotate_two(stack_a, stack_b);
			ft_putstr_fd("rrr\n", 1);
		}
	}
}

static void	make_moves_stack_a(t_list **stack_a, int shift_a)
{
	if (shift_a > 0)
	{
		while (shift_a--)
		{
			rotate(stack_a);
			ft_putstr_fd("ra\n", 1);
		}
	}
	else if (shift_a < 0)
	{
		while (shift_a++)
		{
			reverse_rotate(stack_a);
			ft_putstr_fd("rra\n", 1);
		}
	}
}

static void	make_moves_stack_b(t_list **stack_b, int shift_b)
{
	if (shift_b > 0)
	{
		while (shift_b--)
		{
			rotate(stack_b);
			ft_putstr_fd("rb\n", 1);
		}
	}
	else if (shift_b < 0)
	{
		while (shift_b++)
		{
			reverse_rotate(stack_b);
			ft_putstr_fd("rrb\n", 1);
		}
	}
}

void	push_back(t_list **stack_a, t_list **stack_b)
{
	int	rotation;

	while (*stack_b)
	{
		rotation = find_position_in_a(*stack_a, (*stack_b)->content);
		if (rotation > size_of_stack(*stack_a) / 2)
			rotation = (size_of_stack(*stack_a) - rotation) * (-1);
		make_moves_stack_a(stack_a, rotation);
		push(stack_b, stack_a);
		ft_putstr_fd("pa\n", 1);
	}
}
