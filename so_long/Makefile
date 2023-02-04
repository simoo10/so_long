CFLAGS	= -Wall -Wextra -Werror
CC = cc
LIBC	= ar -rc
RM		= rm -f
NAME	= so_long
NAME_BONUS = so_long_bonus
SRC		=	main.c \
				libft_utils/get_next_line.c \
				libft_utils/get_next_line_utils.c \
				libft_utils/utils.c \
				libft_utils/utils2.c \
				checking/check_map.c \
				checking/check_map2.c \
				checking/check_utils.c \
				checking/check_utils2.c \
				checking/check_map3.c \
				show_map.c \
				move.c \
				move_button.c \
				move_img.c \
				show_map_utils.c \

SRC_BONUS = bonus/main_bonus.c \
				bonus/libft_bonus/get_next_line.c \
				bonus/libft_bonus/get_next_line_utils.c \
				bonus/libft_bonus/utils_bonus.c \
				bonus/libft_bonus/utils2_bonus.c \
				bonus/libft_bonus/utils3_bonus.c \
				bonus/checking_bonus/check_map_bonus.c \
				bonus/show_map_bonus.c \
				bonus/move_bonus.c \
				bonus/move_button_bonus.c \
				bonus/animation_bonus.c \
				bonus/move_img_bonus.c \
				bonus/ennemi_bonus.c \
				bonus/checking_bonus/check_map2_bonus.c \
				bonus/checking_bonus/check_map3_bonus.c \
				bonus/show_map_utils_bonus.c \
				bonus/checking_bonus/check_utils_bonus.c \
				bonus/checking_bonus/check_utils2_bonus.c \
				
OBJ	= $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
		$(CC) $(CFLAGS) $(OBJ_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

clean:
		$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
		$(RM) $(NAME) $(NAME_BONUS)

re:	fclean all bonus
