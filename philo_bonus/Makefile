NAME = philo_bonus
CFLAGS = -Wall -Wextra -Werror -g3
TFLAGS = -pthread
VALGRIND_LOG = valgrind.log

# Colors Definition 
GREEN = "\033[32;1m"
RED = "\033[31;1m"
CYAN = "\033[36;1;3;208m"
WHITE = "\033[37;1;4m"
COLOR_LIMITER = "\033[0m"

# Paths Definitions
HEADER_PATH = ./includes
BIN_PATH = ./bin/
SOURCES_PATH = ./src/

SOURCES = \
	error_bonus.c \
	init_bonus.c \
	main_bonus.c \
	philo_actions_bonus.c \
	philo_life_bonus.c \
	philo_utils_bonus.c \
	utils_bonus.c \

OBJECTS = $(addprefix $(BIN_PATH), $(SOURCES:%.c=%.o))

all: $(BIN_PATH) $(NAME)

$(BIN_PATH)%.o: $(SOURCES_PATH)%.c
	@echo $(GREEN)[Compiling]$(COLOR_LIMITER) $(WHITE)$(notdir $(<))...$(COLOR_LIMITER)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_PATH)
	@echo " "

$(NAME): $(OBJECTS)
	@echo $(CYAN)" ----------------------------------------------------"$(COLOR_LIMITER)
	@echo $(CYAN)"| PHILO_BONUS executable was created successfully!! |"$(COLOR_LIMITER)
	@echo $(CYAN)"----------------------------------------------------"$(COLOR_LIMITER)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(TFLAGS)
	@echo " "

$(BIN_PATH):
	@mkdir -p $(BIN_PATH)

valgrind: all
	@valgrind --leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	--log-file=$(VALGRIND_LOG) \
	./$(NAME) 4 410 200 200

clean:
	@echo $(RED)[Removing Objects]$(COLOR_LIMITER)
	@rm -rf $(BIN_PATH)

fclean: clean
	@echo $(RED)[Removing $(NAME)]$(COLOR_LIMITER)
	@rm -f $(NAME)
	@rm -f $(VALGRIND_LOG)

re: fclean
	@make --no-print-directory

.PHONY: all clean fclean re