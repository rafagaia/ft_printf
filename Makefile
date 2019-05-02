# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgaia <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/23 21:52:40 by rgaia             #+#    #+#              #
#    Updated: 2019/04/29 17:42:33 by rgaia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRC_DIR = src/
LIB_DIR = libft/
#TEST_DIR = test/

SRC_FILES = ft_printf.c cspdiu_conversions.c oxXf_conversions.c tokenizer.c \
			modifiers.c \

LIBFT_FILES = ft_isdigit.c ft_itoa.c ft_itoa_base_unsigned.c ft_memalloc.c \
			ft_putchar.c ft_putstr.c ft_numdigit.c ft_putendl.c ft_putnbr.c \
			ft_strcat.c ft_strncat.c ft_strchr.c ft_strdel.c ft_strdup.c \
			ft_strequ.c ft_strcpy.c ft_strncpy.c ft_strnew.c ft_tolower.c \
			ft_toupper.c ft_atoi.c ft_bzero.c ft_islower.c ft_isupper.c \
			ft_strclr.c ft_puterror.c ft_strlen.c ft_strndup.c ft_memdel.c \
			ft_strjoin.c \ 

#TEST_FILES = main_test.c #tokenization_test.c token_unit_test.c \
			 			# token_combination_2.c

#Source files path
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
LIBFT = $(addprefix $(LIB_DIR), $(LIBFT_FILES))
#TEST_SRC = $(addprefix $(TEST_DIR), $(TEST_FILES))

#Objects
OBJ = $(SRC_FILES:.c=.o) $(LIBFT_FILES:.c=.o)
#TEST_OBJ = $(TEST_FILES:.c=.o)

#Flags
INC = -Iincludes/
FLAGS = -Wall -Wextra #-Werror

all: $(NAME)

#Compile command:
$(NAME):
	@echo "Compiling... Wait a moment ..."
	@gcc -c $(FLAGS) $(SRC) $(LIBFT)
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

