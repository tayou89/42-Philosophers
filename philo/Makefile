# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 11:43:27 by tayou             #+#    #+#              #
#    Updated: 2023/07/03 11:44:53 by tayou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CCFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
COMMON_FILE = minishell \
			  check_argc \
			  make_initial_setting \
			  handle_signal \
			  get_input_and_process_data
COMMON_SRC = $(addprefix $(COMMON_DIR)/, $(addsuffix .c, $(COMMON_FILE)))
COMMON_OBJ = $(addprefix $(COMMON_DIR)/, $(addsuffix .o, $(COMMON_FILE)))

all : $(NAME)

clean : 
	make -C $(LIBFT_DIR) fclean
	$(RM) $(RMFLAGS) $(COMMON_OBJ)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

$(NAME) : $(LIBFT) $(COMMON_OBJ)
	$(CC) $(CCFLAGS) -o $(NAME) $^
	
$(LIBFT) : 
	make bonus -C $(LIBFT_DIR) all

%.o : %.c
	$(CC) $(CCFLAGS) -o $@ -c $< 

.PHONY : all clean fclean re libft bonus
