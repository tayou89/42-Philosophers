# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 13:15:02 by tayou             #+#    #+#              #
#    Updated: 2023/07/21 12:59:53 by tayou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = cc
CCFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf
FILE_NAME = philo \
			check_exception ft_atoi \
			create_data \
			create_philo_process \
			execute_philo_process take_philo_routine \
			execute_parent_process \
			ft_semaphore ft_thread \
			util print_philo

SOURCE_FILE = $(addsuffix _bonus.c, $(FILE_NAME))
OBJECT_FILE = $(addsuffix _bonus.o, $(FILE_NAME))

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

.PHONY : all clean fclean re bonus
