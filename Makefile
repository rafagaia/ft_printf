# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgaia <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/23 21:52:40 by rgaia             #+#    #+#              #
#    Updated: 2019/04/25 05:58:17 by rgaia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRC_DIR = src/
LIB_DIR = lib/

SRC_FILES = ft_printf.c cspdiu_conversions.c oxXf_conversions.c tokenizer.c
LIB_FILES = libft.a


#Source files path
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
LIB = $(addprefix $(LIB_DIR), $(LIB_FILES))

#Objects
OBJ = $(SRC_FILES:.c=.o)

#Flags
INC = -I
FLAGS = -Wall -Wextra

all: $(NAME)

#Compile command:
$(NAME):
	@echo "Compiling... Wait a moment ..."
	@gcc -c $(FLAGS) $(SRC) $(INC) $(LIB)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) Has Been Generated!!!"

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

