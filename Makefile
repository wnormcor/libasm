# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wnormcor <wnormcor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 07:26:21 by wnormcor          #+#    #+#              #
#    Updated: 2020/10/31 14:19:52 by wnormcor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libasm.a
NAME_MAIN =	main

SRC = 		ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
SRC_MAIN =	main.c

OBJ =		$(addprefix obj/, $(SRC:%.s=%.o))
OBJ_MAIN =	$(addprefix obj/, $(SRC_MAIN:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

obj/%.o : src/%.s
	@mkdir -p obj
	nasm -f macho64 $< -o $@

$(NAME_MAIN): $(NAME) $(OBJ_MAIN)
	gcc -Wall -Wextra -Werror $(NAME) $(OBJ_MAIN) -o $(NAME_MAIN)

obj/%.o : src/%.c src/libasm.h
	@mkdir -p obj
	gcc -Wall -Wextra -Werror -g -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_MAIN)
	@if [ -d obj ]; then rmdir obj; fi

fclean: clean
	rm -f $(NAME) $(NAME_MAIN)

re: fclean all

.PHONY = all clean fclean re
