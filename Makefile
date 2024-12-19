NAME = so_long

LIBFTDIR = Libft
LIBFT = $(LIBFTDIR)/libft.a

MLXDIR = mlx
MLX = $(MLXDIR)/libmlx.a

FT_PRINTFDIR = ft_printf
FT_PRINTF = $(FT_PRINTFDIR)/libftprintf.a

SRC = src/so_long.c src/map.c src/controls1.c src/controls2.c src/check_errors1.c src/check_errors2.c src/check_errors3.c src/start_game.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I$(MLXDIR)
LDFLAGS = -L$(LIBFTDIR) -lft -L$(MLXDIR) -lmlx -lXext -lX11

all: $(LIBFT) $(FT_PRINTF) $(MLX) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) $(MLX) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(FT_PRINTF) :
	$(MAKE) -C $(FT_PRINTFDIR)

$(MLX):
	$(MAKE) -C $(MLXDIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(MLXDIR) clean
	$(MAKE) -C $(FT_PRINTFDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(MLXDIR) fclean
	$(MAKE) -C $(FT_PRINTFDIR) fclean

re: fclean all

.PHONY: all clean fclean re