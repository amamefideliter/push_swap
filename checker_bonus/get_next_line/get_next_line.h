/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:56:34 by dzubkova          #+#    #+#             */
/*   Updated: 2024/02/15 14:06:39 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list_old
{
	void				*content;
	struct s_list_old	*next;
}					t_list_old;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	ft_add_new(t_list_old **lst, void *content);
void	free_list_gnl(t_list_old *head);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
