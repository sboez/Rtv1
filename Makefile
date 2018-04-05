## Name of Project

NAME = rtv1

## Color for display

COLOR = \0033[1;35m

## List of Directories

INC_DIR = includes
OBJ_DIR = objs
SRC_DIR = src
LIB_DIR = libft

## Compilating Utilities

FLAGS = -Wall -Wextra -Werror -Ofast
INC = $(INC_DIR:%=-I ./%)
LIB = -L $(LIB_DIR) -lft
MLX = ./minilibx_macos/libmlx.a -framework OpenGL -framework AppKit
CC = clang $(FLAGS) $(INC)

## List of Functions

SRC_FT = rtv1_init \
		 rtv1_main \
		 rtv1_parse \
		 rtv1_parse_check \
		 rtv1_set_obj \
		 rtv1_usefull \
		 rtv1_vec_calc \
		 rtv1_vec_calc2 \
		 rtv1_vec_calc3 \
		 rtv1_vec_calc4 \
		 rtv1_finder \
		 rtv1_finder2 \
		 rtv1_display \
		 rtv1_color

## List of Utilities

OBJ = $(SRC_FT:%=$(OBJ_DIR)/%.o)
SRC = $(SRC_FT:%=$(SRC_DIR)/%.c)

## Rules of Makefile

all: $(NAME)
	@echo "$(COLOR)$(NAME)\t\t\0033[1;30m[All OK]\0033[0;37m"

$(OBJ_DIR):
	@mkdir -p $@
	@echo "$(COLOR)Creating    : \0033[0;32m$@\0033[0;37m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $< -o $@
	@echo "$(COLOR)Compiling : \0033[0;32m$(@:$(OBJ_DIR)/%=%)\0033[0;37m"

$(NAME): $(OBJ_DIR) $(SRC)
	@echo "\033[35m( ⚆ _ ⚆ ) Compiling... Wait a sec.\033[0m"
	@$(MAKE) -j -s $(OBJ)
	@echo "$(COLOR)Objects\t\t\0033[0;32m[Created]\0033[0;37m"
	@make -j -s -C $(LIB_DIR)
	@$(CC) $(LIB) $(OBJ) $(MLX) -o $@
	@echo "$(COLOR)$(NAME)\t\t\0033[0;32m[Created]\0033[0;37m"
	@echo "\033[36mಠ‿↼ $(NAME) generated!\033[0m"

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIB_DIR)
	@echo "$(COLOR)Objects\t\t\0033[0;31m[Deleted]\0033[0;37m"
	@echo "\033[33mಠ_ಥ Objects removed!\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_DIR)
	@echo "$(COLOR)$(NAME)\t\t\0033[0;31m[Deleted]\0033[0;37m"
	@echo "\033[33m｡◕‿◕｡ $(NAME) removed!\033[0m"

re: fclean all

norme:
	@norminette $(SRC) $(INC_DIR)/
	@make norme -C $(LIB_DIR)

.PHONY: all clean fclean re norme
