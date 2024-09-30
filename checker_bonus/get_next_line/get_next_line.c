/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:16:37 by dzubkova          #+#    #+#             */
/*   Updated: 2024/02/16 13:09:31 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

static char	*concatenate(t_list_old *parts);
static char	*copy_string_idx(char *buffer, int start, int end);
static int	append_part(char *buffer, int *position, t_list_old **parts);
static int	parse_buffer(int *position, char *buffer,
				t_list_old **parts, int fd);

char	*get_next_line(int fd)
{
	static char			buffer[BUFFER_SIZE];
	static int			position = -1;
	int					new_line_found;
	int					read_size;
	t_list_old			*parts;

	parts = NULL;
	new_line_found = 0;
	read_size = BUFFER_SIZE;
	if (position >= 0)
		new_line_found = append_part(buffer, &position, &parts);
	if (new_line_found)
		return (concatenate(parts));
	while (read_size > 0)
	{
		read_size = parse_buffer(&position, buffer, &parts, fd);
		if (read_size == -1)
			return (NULL);
		new_line_found = append_part(buffer, &position, &parts);
		if (new_line_found)
			return (concatenate(parts));
	}
	free_list_gnl(parts);
	return (NULL);
}

static int	parse_buffer(int *position, char *buffer,
			t_list_old **parts, int fd)
{
	int	read_size;

	read_size = read(fd, buffer, BUFFER_SIZE);
	if (read_size < 0)
	{
		free_list_gnl(*parts);
		*position = -1;
		return (-1);
	}
	else if (read_size == 0 && *position == -1)
	{
		free_list_gnl(*parts);
		return (-1);
	}
	else
	{
		if (read_size < BUFFER_SIZE)
			buffer[read_size] = '\0';
		*position = 0;
	}
	return (read_size);
}

static int	append_part(char *buffer, int *position, t_list_old **parts)
{
	int		idx;

	idx = *position;
	while (idx < BUFFER_SIZE && buffer[idx])
	{
		if (buffer[idx] == '\n')
		{
			ft_add_new(parts, copy_string_idx(buffer, *position, idx));
			if (idx == (int)ft_strlen(buffer) - 1)
				*position = -1;
			else
				*position = idx + 1;
			return (1);
		}
		idx++;
	}
	ft_add_new(parts, copy_string_idx(buffer, *position, idx));
	if (idx < BUFFER_SIZE)
	{
		*position = -1;
		return (1);
	}
	return (0);
}

static char	*copy_string_idx(char *buffer, int start, int end)
{
	char	*copy;
	int		idx;
	int		n;

	n = end - start;
	copy = malloc((sizeof(char) * n) + 2);
	if (!copy)
		return (NULL);
	idx = 0;
	while (start <= end)
	{
		copy[idx] = buffer[start];
		idx++;
		start++;
	}
	copy[idx] = '\0';
	return (copy);
}

static char	*concatenate(t_list_old *parts)
{
	char		*tmp;
	size_t		size;
	t_list_old	*copy;
	t_list_old	*head;

	size = 0;
	copy = parts;
	head = parts;
	while (parts)
	{
		size += ft_strlen(parts->content);
		parts = parts->next;
	}
	tmp = malloc(sizeof(char) * (size + 1));
	if (!tmp)
		return (NULL);
	while (copy)
	{
		ft_memcpy(tmp, copy->content, ft_strlen(copy->content));
		tmp += ft_strlen(copy->content);
		copy = copy->next;
	}
	*tmp = '\0';
	free_list_gnl(head);
	return (tmp - size);
}
