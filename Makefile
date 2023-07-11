#Target Binary Program
NAME = Checker_rush

#Color scheme
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

#Flags
FLAGS = -Wall -Werror -Wextra -I includes


#Direcory locations
SRC_DIR = srcs/
OBJS_DIR = obj/

#Sources
SRCS := auxFunctions.c checker.c main.c validity_utils.c

#OBJ path
OBJS = $(patsubst %, $(OBJS_DIR)%, $(SRCS:.c=.o))

all: $(NAME)
$(NAME): $(OBJS_DIR) $(OBJS)
	@cc $(FLAGS) $(OBJS) -o $@
	@cd visualizer && make
	@echo "$(COLOUR_GREEN)$@ created$(COLOUR_END)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "$(COLOUR_BLUE)object directory created$(COLOUR_END)"

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	@cc $(FLAGS) -c $< -o $@
	@echo "$(COLOUR_BLUE)$@ created$(COLOUR_END)"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(COLOUR_BLUE)object directory cleaned$(COLOUR_END)"

fclean: clean
	@rm -rf $(OBJS_DIR)
	@rm -f $(NAME)
	@echo "$(COLOUR_RED)$(NAME) removed$(COLOUR_END)"

re: fclean all
