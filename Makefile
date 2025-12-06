# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 14:00:12 by natakaha          #+#    #+#              #
#    Updated: 2025/11/04 14:00:12 by natakaha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME =  push_swap
BONUS_NAME = checker
SRCS = util_make_node.c\
       util_info_node.c\
	   util_perth.c\
	   util_find_chunk.c\
	   alg_moriP_sort.c\
	   alg_sort3.c\
	   list_make_node.c\
	   ope_push.c\
	   ope_reverse_rotate.c\
	   ope_rotate.c\
	   ope_swap.c\
	   ope_manage.c\
	   ope_main.c\

BONUS_SRCS = util_make_node.c\
       		 util_info_node.c\
			 util_perth.c\
			 util_find_chunk.c\
			 list_make_node.c\
			 checker_gnl_bonus.c\
			 checker_gnl_utils_bonus.c\
			 checker_ope_manage_bonus.c\
			 checker_ope_push_bonus.c\
			 checker_ope_reverse_rotate_bonus.c\
			 checker_ope_rotate_bonus.c\
			 checker_ope_swap_bonus.c\


OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all
