/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:34:37 by dzubkova          #+#    #+#             */
/*   Updated: 2024/02/16 13:29:03 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	check_duplicates(int *arr, int size);
static int	check_input(int *arg_array, int argc, char **argv);
static void	print_result(t_list *stack_a, t_list *stack_b);

int	main(int argc, char **argv)
{
	int		*arg_array;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (1);
	arg_array = malloc(sizeof(int) * (argc - 1));
	if (!arg_array)
		return (1);
	if (!check_input(arg_array, argc, argv))
	{
		free(arg_array);
		return (2);
	}
	stack_a = initialize_stack(arg_array, argc - 1);
	stack_b = NULL;
	free(arg_array);
	if (!read_commands(&stack_a, &stack_b))
	{
		terminate_stacks(stack_a, stack_b);
		ft_putendl_fd("Error", 2);
		return (1);
	}
	print_result(stack_a, stack_b);
	return (0);
}

static void	print_result(t_list *stack_a, t_list *stack_b)
{
	if (is_sorted_stack(stack_a) && !stack_b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	terminate_stacks(stack_a, stack_b);
}

static int	check_input(int *arg_array, int argc, char **argv)
{
	int	count;

	count = 1;
	while (count < argc)
	{
		if (valid_integer(argv[count]))
			arg_array[count - 1] = ft_atoi(argv[count]);
		else
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		count++;
	}
	if (check_duplicates(arg_array, argc - 1))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

static int	check_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted_stack(t_list *stack)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = stack;
	prev = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->content < prev->content)
			return (0);
		prev = tmp;
		tmp = tmp->next;
	}
	return (1);
}
