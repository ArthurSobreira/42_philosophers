NAME = philo
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
	error.c \
	getters.c \
	getters2.c \
	init.c \
	main.c \
	monitor.c \
	philo_actions.c \
	philo_life.c \
	philo_utils.c \
	utils.c \

OBJECTS = $(addprefix $(BIN_PATH), $(SOURCES:%.c=%.o))

all: $(BIN_PATH) $(NAME)

$(BIN_PATH)%.o: $(SOURCES_PATH)%.c
	@echo $(GREEN)[Compiling]$(COLOR_LIMITER) $(WHITE)$(notdir $(<))...$(COLOR_LIMITER)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_PATH)
	@echo " "

$(NAME): $(OBJECTS)
	@echo $(CYAN)" ----------------------------------------------"$(COLOR_LIMITER)
	@echo $(CYAN)"| PHILO executable was created successfully!! |"$(COLOR_LIMITER)
	@echo $(CYAN)"----------------------------------------------"$(COLOR_LIMITER)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(TFLAGS)
	@echo " "

$(BIN_PATH):
	@mkdir -p $(BIN_PATH)

valgrind: all
	@valgrind --tool=helgrind \
	--log-file=$(VALGRIND_LOG) \
	./$(NAME) 4 310 200 100

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