# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wawong <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/03 22:26:29 by wawong            #+#    #+#              #
#    Updated: 2018/12/03 20:42:52 by wawong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC		= ft_printf.c handle.c support.c

LIB		= ft_memset.c ft_memalloc.c ft_putchar.c ft_itoa_base.c ft_putstr.c ft_putnbr.c ft_itoa_max.c ft_strshort.c ft_strset.c ft_strncmp.c\
ft_strdup.c ft_strnew.c ft_alloc.c ft_atoi.c ft_chartostr.c ft_strcat.c ft_strchr.c ft_strcpy.c ft_strlen.c ft_strsub.c ft_strncpy.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))
OBJ		+= $(addprefix $(OBJDIR),$(LIB:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

SRCDIR	= ./src/
LIBDIR	= ./src/libft/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj $(OBJ) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c 
	@$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<
	@echo "\033[1;32mMake : $<\033[m"

$(OBJDIR)%.o:$(LIBDIR)%.c 
	@$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<
	@echo "\033[1;32mMake : $<\033[m"

$(NAME):
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
