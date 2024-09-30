/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:52:13 by dzubkova          #+#    #+#             */
/*   Updated: 2024/02/16 15:00:04 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	check_instruction(char *line, t_list **stack_a, t_list **stack_b);

int	read_commands(t_list **stack_a, t_list **stack_b)
{
	char	*line;
	int		got_instructions;

	got_instructions = 0;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!check_instruction(line, stack_a, stack_b))
		{
			free(line);
			return (0);
		}
		got_instructions = 1;
		free(line);
	}
	if (got_instructions)
		return (1);
	return (2);
}

static int	check_instruction(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp("ra\n", line, sizeof(line)))
		rotate(stack_a);
	else if (!ft_strncmp("rb\n", line, sizeof(line)))
		rotate(stack_b);
	else if (!ft_strncmp("rr\n", line, sizeof(line)))
		rotate_two(stack_a, stack_b);
	else if (!ft_strncmp("rra\n", line, sizeof(line)))
		reverse_rotate(stack_a);
	else if (!ft_strncmp("rrb\n", line, sizeof(line)))
		reverse_rotate(stack_b);
	else if (!ft_strncmp("rrr\n", line, sizeof(line)))
		reverse_rotate_two(stack_a, stack_b);
	else if (!ft_strncmp("sa\n", line, sizeof(line)))
		swap(stack_a);
	else if (!ft_strncmp("sb\n", line, sizeof(line)))
		swap(stack_b);
	else if (!ft_strncmp("ss\n", line, sizeof(line)))
		swap_both(stack_a, stack_a);
	else if (!ft_strncmp("pa\n", line, sizeof(line)))
		push(stack_b, stack_a);
	else if (!ft_strncmp("pb\n", line, sizeof(line)))
		push(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	terminate_stacks(t_list *stack_a, t_list *stack_b)
{
	free_list(&stack_a);
	free_list(&stack_b);
}
