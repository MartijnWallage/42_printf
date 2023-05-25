# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwallage <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 13:18:50 by mwallage          #+#    #+#              #
#    Updated: 2023/05/25 15:28:41 by mwallage         ###   ########.fr        #
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
OBJS	:= $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
NAME 	:= libftprintf.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	mv $(LIBDIR)/$(LIBFT) libftprintf.a
	make clean -C ./$(LIBDIR)
	$(AR) rcs $@ $(OBJS)

$(LIBFT):
	make bonus -C ./$(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)/*.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
