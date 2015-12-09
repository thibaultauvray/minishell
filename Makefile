# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tauvray <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/17 11:01:12 by tauvray           #+#    #+#              #
#*   Updated: 2014/11/21 15:01:43 by tauvray          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

# *********************************VARIABLES***********************************#

NAME = ft_minishell1

SRC_DIR = srcs/

SRC = srcs/main.c \
	  srcs/ft_signal.c \
	  srcs/env.c \
	  srcs/errors.c \
	  srcs/set_env.c \
	  srcs/unset_env.c \
	  srcs/ft_cd.c \
	  srcs/ft_cd2.c \
	  srcs/env2.c \
	  srcs/env3.c \
	  srcs/errors2.c \
	  srcs/ft_put.c \
	  srcs/ft_put2.c \
	  srcs/set_env2.c \
	  srcs/ft_cd3.c \
	  srcs/exit.c

INC = includes/

LIBINC = libft/includes/

LIB = libft.a

BIN_DIR = bin/

BIN = main.o \
	  ft_signal.o \
	  env.o \
	  errors.o \
	  set_env.o \
	  unset_env.o \
	  ft_cd.o \
	  env2.o \
	  env3.o \
	  errors2.o \
	  ft_put.o \
	  ft_put2.o \
	  set_env2.o \
	  ft_cd2.o \
	  ft_cd3.o \
	  exit.o

CC = gcc

OPTS = -Wall -Werror -Wextra -g

# *********************************RULES***************************************#

all			: $(NAME)

$(NAME)		: 
	make -C libft/
	$(CC) $(OPTS) -I $(LIBINC) -I includes/ -c $(SRC)
	$(CC) $(OPTS) $(BIN) -L libft/ -lft -o $(NAME)

lib			:

clean 		:
	make -C libft/ clean
	rm -f $(BIN)

fclean		: clean
	make -C libft/ fclean
	rm -f $(NAME)

re			: fclean all 
