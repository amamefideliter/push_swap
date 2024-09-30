/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:07:41 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/30 12:51:26 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	check_duplicates(int *arr, int size);
static int	check_input(int *arg_array, int argc, char **argv);

int	main(int argc, char **argv)
{
	int		*arg_array;
	t_list	*stack_a;

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
	if (!is_sorted(arg_array, argc - 1))
	{
		stack_a = initialize_stack(arg_array, argc - 1);
		sort_stack(&stack_a);
	}
	free(arg_array);
	return (0);
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
