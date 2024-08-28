# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 11:43:27 by tayou             #+#    #+#              #
#    Updated: 2023/07/31 15:07:23 by tayou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
BONUS_NAME = philo_bonus

# Compiling Commands
GCC = gcc
GCC_FLAGS = -Wall -Wextra -Werror
RM = rm
RM_FLAGS = -rf

# Path
SOURCE_PATH = sources/
OBJECT_PATH = objects/
HEADER_PATH = headers/
MANDATORY_PATH = mandatory/
BONUS_PATH = bonus/

# Source Names
MANDATORY_NAMES = philo \
				  check_exception_exist ft_atoi \
				  create_data make_philo_list \
				  create_philo_thread ft_main_thread ft_philo_thread \
				  fork_action take_philo_routine \
				  util print_philo \
				  free_thread_and_mutex free_mallocated_data \

BONUS_NAMES = philo \
	    	  check_exception ft_atoi \
	    	  create_data \
	    	  create_philo_process \
	    	  execute_philo_process take_philo_routine \
	    	  execute_parent_process \
	    	  ft_semaphore ft_thread \
	    	  util print_philo ft_itoa ft_strjoin

# Sources
MANDATORY_SOURCES = $(addprefix $(SOURCE_PATH)$(MANDATORY_PATH), $(addsuffix .c, $(MANDATORY_NAMES)))
BONUS_SOURCES = $(addprefix $(SOURCE_PATH)$(BONUS_PATH), $(addsuffix _bonus.c, $(BONUS_NAMES)))

# Objects
MANDATORY_OBJECTS = $(addprefix $(OBJECT_PATH)$(MANDATORY_PATH), $(addsuffix .o, $(MANDATORY_NAMES)))
BONUS_OBJECTS = $(addprefix $(OBJECT_PATH)$(BONUS_PATH), $(addsuffix _bonus.o, $(BONUS_NAMES)))

all: $(NAME)

$(NAME): $(MANDATORY_OBJECTS)
	$(GCC) $(GCC_FLAGS) -o $(NAME) $^

$(OBJECT_PATH)$(MANDATORY_PATH)%.o: $(SOURCE_PATH)$(MANDATORY_PATH)%.c
	@mkdir -p $(dir $@)
	$(GCC) $(GCC_FLAGS) -I$(HEADER_PATH) -o $@ -c $< 

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJECTS)
	$(GCC) $(GCC_FLAGS) -o $(BONUS_NAME) $^

$(OBJECT_PATH)$(BONUS_PATH)%.o: $(SOURCE_PATH)$(BONUS_PATH)%.c
	@mkdir -p $(dir $@)
	$(GCC) $(GCC_FLAGS) -I$(HEADER_PATH) -o $@ -c $< 

clean: 
	$(RM) $(RM_FLAGS) $(OBJECT_PATH)

fclean: clean
	$(RM) $(RM_FLAGS) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY : all clean fclean re bonus