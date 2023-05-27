# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwallage <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 13:18:50 by mwallage          #+#    #+#              #
#    Updated: 2023/05/25 20:20:54 by mwallage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= cc
AR		:= ar
CFLAGS	:= -Wall -Wextra -Werror
SRCDIR	:= src
OBJDIR	:= obj
INCDIR	:= inc
LIBDIR	:= libft
LIBFT	:= libft.a
SRCS	:= $(wildcard $(SRCDIR)/*.c)
NAME 	:= libftprintf.a

all: $(NAME)

$(OBJDIR):
	mkdir obj

OBJS	:= $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

$(NAME): $(OBJS)
	$(AR) rcs $@ $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJDIR)/*.o
	make clean -C ./$(LIBDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C ./$(LIBDIR)

re: fclean $(NAME)

.PHONY: all clean fclean re
