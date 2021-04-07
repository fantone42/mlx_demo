DIR_HEADERS	=	./includes/

DIR_SRCS =	./srcs/

			
SRC		=	geometry/vector.c \
			figure/sphere.c \
			utils/error_exit.c \
			main.c

SRCS	=	$(addprefix $(DIR_SRCS), $(SRC))

OBJS	=	$(SRCS:.c=.o)

NAME	=	mlx

LIBMLX	=	libmlx.dylib

CC		=	gcc
RM		=	rm -f
CFLAGS 	=	-Wall -Wextra -Werror

%.o: %.c
			$(CC) $(CFLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(NAME):	$(OBJS)
			make -C ./minilibx_mms_20200219
			cp ./minilibx_mms_20200219/libmlx.dylib .
			$(CC) $(CFLAGS) -I $(DIR_HEADERS) $(LIBMLX) $(OBJS) -o $(NAME)

all:	$(NAME)

clean:	
	$(RM) $(OBJS)
	make clean -C ./minilibx_mms_20200219

fclean:	clean
			$(RM) $(LIBMLX)
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	clean fclean re all