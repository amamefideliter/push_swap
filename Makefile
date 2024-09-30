# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 12:18:09 by dzubkova          #+#    #+#              #
#    Updated: 2024/09/30 12:52:35 by dzubkova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PFX = sources/

SRCS = $(PFX)final_sort_utils.c $(PFX)find_in_stack_utils.c $(PFX)general_utils.c \
		$(PFX)make_moves_stack.c $(PFX)rotate_utils.c $(PFX)sort_stack.c $(PFX)swap_utils.c $(PFX)utils.c \
		$(PFX)sort_three.c main.c

BSRCS = checker_bonus/checker_main.c checker_bonus/read_instructions.c

GNLSRCS = checker_bonus/get_next_line/get_next_line_utils.c checker_bonus/get_next_line/get_next_line.c

OFILES = $(SRCS:.c=.o)
BOFILES = $(BSRCS:.c=.o)
GNLOFILES = $(GNLSRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
BONUS_NAME = checker
MAKE = make

all: $(NAME)

$(NAME): $(OFILES)
	$(MAKE) bonus -C ./libft
	cc $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME)

%.o: %.c
	cc -c $(CFLAGS) $< -o $@

bonus:
	$(MAKE) bonus -C ./libft
	cc $(CFLAGS) $(BSRCS) $(GNLSRCS) utils.c swap_utils.c rotate_utils.c general_utils.c libft/libft.a -o $(BONUS_NAME)

clean:
	rm -f $(OFILES)
	$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME)
	rm -f libft.a
	rm -f $(BONUS_NAME)
	$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re bonus