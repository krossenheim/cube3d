SOURCES_DIR = src/

SOURCES_FLS	=	main.c \
				bindings/bindings.c \
				initialization/initialization.c 



SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_FLS))
OBJS	=	$(SOURCES:%.c=%.o)
NAME = cube3d.out

MLX_LIB_DIR = mlx_linux

CFLAGS	=	-Wall	-Wextra	-Werror -g -I ./includes/ -Lmlx_linux -lmlx_Linux -L/usr/lib -I ./mlx_linux/ -lXext -lX11 -lm -lz
%.o: %.c
	cc -g -Wall -Wextra -Werror -I ./includes/ -I/usr/include -Imlx_linux -c $< -o $@

$(NAME): $(OBJS) mlx_lib
	cc $(OBJS) $(CFLAGS) -g -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

mlx_lib:
	$(MAKE) -C $(MLX_LIB_DIR)
	
all:	$(NAME)
	
re: clean all

clean:
	rm	-f	$(OBJS) $(NAME)
	$(MAKE) -C $(MLX_LIB_DIR) clean

fclean:
	rm	-f	$(OBJS) $(NAME)
	$(MAKE) -C $(MLX_LIB_DIR)  clean


.phony: make re clean run fclean mlx_lib



