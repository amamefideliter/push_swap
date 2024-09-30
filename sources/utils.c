/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:07:53 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/30 12:53:24 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*initialize_stack(int *array, int size)
{
	int		idx;
	t_list	*stack;

	idx = 0;
	stack = NULL;
	while (idx < size)
	{
		ft_lstadd_back(&stack, ft_lstnew(array[idx]));
		idx++;
	}
	return (stack);
}

int	valid_integer(char *number)
{
	char		*copy;
	long int	value_tmp;

	copy = number;
	if (*copy == '-')
	{
		copy++;
		if (!(*copy))
			return (0);
	}
	while (*copy)
	{
		if (!ft_isdigit(*copy))
			return (0);
		copy++;
	}
	copy = number;
	value_tmp = ft_atoi_long(copy);
	if (value_tmp > INT_MAX || value_tmp < INT_MIN)
		return (0);
	return (1);
}

int	is_sorted(int *array, int size)
{
	int	idx;

	idx = 1;
	while (idx < size)
	{
		if (array[idx] < array[idx - 1])
			return (0);
		idx++;
	}
	return (1);
}

int	size_of_stack(t_list *stack)
{
	t_list	*head;
	int		count;

	head = stack;
	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}
