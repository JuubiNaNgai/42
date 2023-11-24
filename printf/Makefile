# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 11:45:38 by aleite-b          #+#    #+#              #
#    Updated: 2023/11/20 13:49:14 by aleite-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

SOURCES = formats.c \
			ft_printf.c \
			utils.c

OBJECTS = $(SOURCES:.c=.o)

HEADER = ft_printf.h

.c.o: $(SOURCES)
	$(CC) $(FLAGS) -I. -c $< -o $(<:.c=.o)

$(NAME): $(OBJECTS) $(HEADER)
	$(AR) $(NAME) $(OBJECTS)

all: $(NAME)

re: clean fclean all

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)


.PHONY: all clean fclean re bonus