# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwallage <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 13:18:50 by mwallage          #+#    #+#              #
#    Updated: 2023/05/27 19:00:38 by mwallage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= cc
AR		:= ar
CFLAGS	:= -Wall -Wextra -Werror
SRCDIR	:= src
OBJDIR	:= obj
INCDIR	:= inc
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

bonus: $(NAME)
	
clean:
	rm -rf $(OBJDIR)/*.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus