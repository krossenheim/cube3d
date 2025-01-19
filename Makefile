SOURCES_DIR = src/

SOURCES_FLS	=	main.c \
				bindings/bindings.c \
				bindings/keys.c \
				bindings/keys_onpress.c \
				freeing/exit_clean.c \
				initialization/initialization.c \
				get_next_line/get_next_line.c \
				parse_map/parse_map.c \
				raycast/raycast.c \
				player/init_player.c \
				debug/debug.c \
				libft/ft_isalpha.c	\
				libft/ft_isdigit.c	\
				libft/ft_isalnum.c	\
				libft/ft_isascii.c	\
				libft/ft_isprint.c	\
				libft/ft_strlen.c	\
				libft/ft_memset.c	\
				libft/ft_bzero.c	\
				libft/ft_memcpy.c	\
				libft/ft_memmove.c	\
				libft/ft_strlcpy.c	\
				libft/ft_strlcat.c	\
				libft/ft_toupper.c	\
				libft/ft_tolower.c	\
				libft/ft_strchr.c	\
				libft/ft_strrchr.c	\
				libft/ft_strncmp.c	\
				libft/ft_memchr.c	\
				libft/ft_memcmp.c	\
				libft/ft_strnstr.c	\
				libft/ft_atoi.c	\
				libft/ft_calloc.c	\
				libft/ft_strdup.c	\
				libft/ft_substr.c	\
				libft/ft_strjoin.c	\
				libft/ft_strtrim.c	\
				libft/ft_split.c	\
				libft/ft_itoa.c	\
				libft/ft_strmapi.c	\
				libft/ft_striteri.c	\
				libft/ft_putchar_fd.c	\
				libft/ft_putstr_fd.c	\
				libft/ft_putendl_fd.c	\
				libft/ft_putnbr_fd.c		\
				libft/ft_lstnew_bonus.c	\
				libft/ft_lstadd_front_bonus.c	\
				libft/ft_lstsize_bonus.c \
				libft/ft_lstlast_bonus.c \
				libft/ft_lstadd_back_bonus.c \
				libft/ft_lstdelone_bonus.c \
				libft/ft_lstclear_bonus.c \
				libft/ft_lstiter_bonus.c \
				libft/ft_lstmap_bonus.c \


SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_FLS))
OBJS	=	$(SOURCES:%.c=%.o)
NAME = cube3d.out

MLX_LIB_DIR = mlx_linux
DEPENDENCIES = $(OBJS:.o=.d)

CFLAGS	=	-Wall	-Wextra	-Werror -MMD -g -I ./includes/ -Lmlx_linux -lmlx_Linux -L/usr/lib -I ./mlx_linux/ -lXext -lX11 -lm -lz

$(NAME): $(OBJS) $(DEPENDENCIES) mlx_lib
	cc $(OBJS) $(CFLAGS) -g -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

-include $(DEPENDENCIES)

mlx_lib:
	$(MAKE) -C $(MLX_LIB_DIR)
	
all:	$(NAME)
	
re: clean all

run:
	./cube3d.out

clean:
	rm	-f	$(OBJS) $(DEPENDENCIES) $(NAME)

fclean:
	rm	-f	$(OBJS) $(DEPENDENCIES) $(NAME)
	$(MAKE) -C $(MLX_LIB_DIR)  clean


.phony: make re clean run fclean mlx_lib



