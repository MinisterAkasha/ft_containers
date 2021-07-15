NAME = ft_container
CC = clang++
FLAGS = -Wall -Wextra -Werror --std=c++98

TEST_DIR = ./Tests
OBJDIR = ./obj
OBJ = $(C_FILES:%.cpp=%.o)
O_FILES = $(addprefix $(OBJDIR)/, $(OBJ))

INCLUDE = -I./src/vector -I./src/Iterator -I./ -I./src/utils -I./src/stack -I./src/map
		
C_FILES = main.cpp
SRC_PATHS = ./

vpath %.cpp $(SRC_PATHS)
vpath %.o $(OBJDIR)

#Tools to edit text
GREEN = \033[1;92m
YELLOW = \033[3;93m
BLUE = \033[3;34m
TEXT_RESET = \033[0;0m

.PHONY: all clean fclean re test

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(INCLUDE) $(O_FILES) -o $@
	@echo "$(GREEN)Success!"

test:
	make -C $(TEST_DIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

%.o: %.cpp
	@echo "$(BLUE)Compiling $<"
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $(OBJDIR)/$@

clean:
	@echo "$(TEXT_RESET)"
	@rm -rf $(OBJDIR)
	@echo "$(YELLOW)Delete 'o' files"

fclean: clean
	@echo "$(TEXT_RESET)"
	@rm -f $(NAME) */**/*.replace */*.replace *.replace test
	@make fclean -C $(TEST_DIR)
	@echo "$(YELLOW)Delete the binary file '$(NAME)'"
	@echo

re: fclean all