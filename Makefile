# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/04 21:35:39 by ttanja            #+#    #+#              #
#    Updated: 2021/09/10 23:17:45 by ttanja           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= push_swap

BONUS	= checker

HEAD	= 

FLAGS =  -Wall -Wextra -Werror

SRC_PA	= ./src/push_swap.c 

SRC    =	./src/ft_atoi.c ./src/ft_isdigit.c ./src/ft_itoa.c\
		 ./src/ft_calloc.c ./src/ft_memset.c ./src/ft_strdup.c\
		 ./src/ft_strlen.c ./src/ft_bzero.c\
		 ./src/ft_free.c ./src/ft_full_a.c ./src/ft_qwic_sort.c\
		 ./src/ft_ar_men6.c ./src/ft_command.c ./src/ft_sort_b.c\
		 ./src/ft_sort_a.c ./src/ft_try.c ./src/ft_mod.c\
		 ./src/ft_split.c ./src/ft_substr.c ./src/ft_strchr.c

SRC_BONUS =	./bonus/bonus_ps.c\
			./bonus/get_next_line.c\
			./bonus/get_next_line_utils.c

OBJ	= $(SRC:.c=.o) 

OBJ_PA = $(SRC_PA:.c=.o) 

OBJ_BON = $(SRC_BONUS:.c=.o) 

$(NAME): $(OBJ) $(OBJ_PA) 
		gcc $(FLAGS)  $^  -o  $@ 

$(BONUS): $(OBJ_BON) $(OBJ)
		gcc  $(FLAGS)  $^  -o  $(BONUS)

%.o: %.c  Makefile ./includes/push_swap.h 
		gcc $(FLAGS)  -c  $< -o  $@ 

all: $(NAME) 

bonus: $(BONUS)

clean:
		/bin/rm -f $(OBJ_PA) $(OBJ) $(OBJ_BON)

fclean: clean
		/bin/rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY:	all clean fclean re bonus

# .SILENT:
