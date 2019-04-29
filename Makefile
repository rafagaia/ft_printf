# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgaia <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/23 21:52:40 by rgaia             #+#    #+#              #
#    Updated: 2019/04/28 16:02:49 by rgaia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRC_DIR = src/
LIB_DIR = lib/
#TEST_DIR = test/

SRC_FILES = ft_printf.c cspdiu_conversions.c oxXf_conversions.c tokenizer.c \
			modifiers.c \

LIB_FILES = libft.a

#TEST_FILES = main_test.c #tokenization_test.c token_unit_test.c \
			 			# token_combination_2.c

#Source files path
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
LIB = $(addprefix $(LIB_DIR), $(LIB_FILES))
#TEST_SRC = $(addprefix $(TEST_DIR), $(TEST_FILES))

#Objects
OBJ = $(SRC_FILES:.c=.o)
#TEST_OBJ = $(TEST_FILES:.c=.o)

#Flags
INC = -I
FLAGS = -Wall -Wextra #-Werror

all: $(NAME)

#Compile command:
$(NAME):
	@echo "Compiling... Wait a moment ..."
	@gcc -c $(FLAGS) $(SRC) $(INC) $(LIB)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) Has Been Generated!!!"
#	@echo "Compiling test/main.c w/ libft & libftprintf.a"
#	@gcc $(FLAGS) $(TEST_SRC) $(INC) $(LIB) libftprintf.a 
#	@echo "Test Compile [complete]"

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

