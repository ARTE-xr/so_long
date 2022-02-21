# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mattif <mattif@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/13 00:28:04 by mattif            #+#    #+#              #
#    Updated: 2022/02/20 22:17:58 by mattif           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Werror -Wextra
LINKS := -lmlx -framework OpenGL -framework AppKit
PRINTF = ft_printf/libftprintf.a
CFILES := mandatory/so_long_utils1.c \
						mandatory/so_long_utils2.c \
						mandatory/so_long.c \
						mandatory/so_long2.c \
						mandatory/making_window.c \
						mandatory/making_window1.c \
						mandatory/making_window2.c \
						mandatory/making_window3.c
						
BCFILES := bonus/so_long_utilsb1.c \
						bonus/so_long_utilsb2.c \
						bonus/so_long_bonus.c \
						bonus/so_long_bonus2.c \
						bonus/making_windowb.c \
						bonus/making_windowb2.c \
						bonus/making_windowb3.c \
						bonus/making_windowb4.c \
						bonus/making_windowb5.c \
						bonus/making_windowb6.c \
						bonus/making_windowb7.c \
 
OFILES := $(CFILES:.c=.o)
BOFILES := $(BCFILES:.c=.o)


INC := mandatory/so_long.h
BINC := bonus/so_long_bonus.h

NAME := so_long
BNAME := so_long_bonus
	
	
$(NAME) : $(OFILES) $(INC) $(PRINTF)
	$(CC) $(CFLAGS) $(CFILES) $(PRINTF) $(LINKS) -o $(NAME)

$(BNAME) : $(BOFILES) $(BINC) $(PRINTF)
	$(CC) $(CFLAGS) $(BCFILES) $(PRINTF) $(LINKS) -o $(BNAME)
	
$(PRINTF):
	make -C ft_printf

all : $(NAME)

bonus : $(BNAME)
clean :
	@rm -rf $(OFILES)
	@rm -rf $(BOFILES)
	make -C ft_printf clean
fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(BNAME)
	make -C ft_printf fclean

re : fclean all
reb : fclean bonus