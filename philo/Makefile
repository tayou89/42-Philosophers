# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 11:43:27 by tayou             #+#    #+#              #
#    Updated: 2023/07/08 01:15:27 by tayou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CCFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
FILE_NAME = philo \
			check_exception_exist ft_atoi \
			create_data_managed_in_main \
			make_philo_list \
			create_philo_thread ft_main_thread ft_philo_thread \
			util \
			free_thread \
			print_data

SOURCE_FILE = $(addsuffix .c, $(FILE_NAME))
OBJECT_FILE = $(addsuffix .o, $(FILE_NAME))

all : $(NAME)

clean : 
	$(RM) $(RMFLAGS) $(OBJECT_FILE)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

$(NAME) : $(OBJECT_FILE)
	$(CC) $(CCFLAGS) -o $(NAME) $^
	
%.o : %.c
	$(CC) $(CCFLAGS) -o $@ -c $< 

.PHONY : all clean fclean re libft bonus
