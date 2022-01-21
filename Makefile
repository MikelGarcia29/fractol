FILES = auxfun		\
	  chardouble	\
	  julia			\
	  keyhook		\
	  main			\
	  mandel		\
	  mousemove		\
	  mousewin		\
	  newfractol	\

NAME = fractol

INC = -I./includes

CFLAGS = -Wextra -Werror -Wall
XFLAGS = -L . -lmlx -framework OpenGL -framework AppKit

S = ./src/
SRCS = $(addprefix $(S), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(S), $(addsuffix .o, $(FILES)))

$(NAME): $(OBJS)
		$(MAKE) -C ./minilibx
		cp ./minilibx/libmlx.a .
		$(CC) $(CFLAGS) $(XFLAGS) $(INC) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJS)
		$(MAKE) clean -C ./minilibx

fclean: clean
		$(RM) $(NAME)
		$(RM) *.a

re: fclean all

.PHONY: all re clean fclean
