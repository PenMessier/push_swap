# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frenna <frenna@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 11:49:35 by Elena             #+#    #+#              #
#    Updated: 2020/02/13 10:42:06 by frenna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PSWP = push_swap
NAME_CHCK = checker
LIB = libft.a
LIB_PATH = libft/

FLAGS = -Wall -Wextra -Werror

SRC_NAME_PSWP = actions.c sort_func.c arr_struct_utils.c arr_struct_push.c checks.c \
					act_apply.c sort_func_extra.c arr_struct_retrieve.c free_err_manag.c push_swap.c

SRC_NAME_CHCK = actions.c sort_func.c arr_struct_utils.c arr_struct_push.c checks.c \
					act_apply.c sort_func_extra.c arr_struct_retrieve.c free_err_manag.c checker.c

SRCS_PSWP = $(addprefix srcs/, $(SRC_NAME_PSWP))
SRCS_CHCK = $(addprefix srcs/, $(SRC_NAME_CHCK))
SRC_DIR = srcs/

OBJ_PSWP = $(addprefix obj/, $(SRC_NAME_PSWP:%.c=%.o))
OBJ_CHCK = $(addprefix obj/, $(SRC_NAME_CHCK:%.c=%.o))
OBJ_DIR = obj/

INCLUDES = includes/pswp.h

all: $(NAME_PSWP) $(NAME_CHCK)

$(NAME_PSWP): $(LIB) $(OBJ_DIR) $(OBJ_PSWP) $(INCLUDES)
	gcc $(FLAGS) $(LIB_PATH)$(LIB) -I $(INCLUDES) $(OBJ_PSWP) -o $(NAME_PSWP)

$(NAME_CHCK): $(LIB) $(OBJ_DIR) $(OBJ_CHCK) $(INCLUDES)
	gcc $(FLAGS) $(LIB_PATH)$(LIB) -I $(INCLUDES) $(OBJ_CHCK) -o $(NAME_CHCK)

$(LIB):
	@make -C $(LIB_PATH)

$(OBJ_DIR):
	@mkdir -p obj

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc $(FLAGS) -c $< -o $@
	
clean:
	/bin/rm -rf $(OBJ_DIR)
	@make clean -C $(LIB_PATH)

fclean: clean
	/bin/rm -f $(NAME_PSWP) $(NAME_CHCK)
	@make fclean -C $(LIB_PATH)

re: fclean all

.PHONY: all clean fclean re
