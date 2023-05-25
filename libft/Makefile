# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwallage <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 17:51:07 by mwallage          #+#    #+#              #
#    Updated: 2023/05/22 16:12:47 by mwallage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
AR := ar
CFLAGS := -Wall -Werror -Wextra

SRC := ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRC2 := ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJ := $(SRC:.c=.o)
OBJ2 := $(SRC2:.c=.o)
NAME := libft.a

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME) $(OBJ) $(OBJ2)
	$(AR) rcs $^
	
clean:
	rm -f $(OBJ) $(OBJ2)

fclean: clean 
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
