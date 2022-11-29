SRCS = 	srcs/main.c \
		srcs/ft_utils.c \
		srcs/ft_data.c \
		srcs/ft_fork.c

OBJS = $(SRCS:.c=.o)

NAME = pipex

LIB = libftpipex.a

CFLAGS = -Wall -Wextra -Werror

.c.o:
	gcc ${CFLAGS} -I includes/ -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	make bonus -C library/libft
	make -C library/ft_printf
	ar crs $(LIB) $(OBJS)
	gcc ${CFLAGS} -I includes/ -L./library/libft -l ft -L./library/ft_printf -l ftprintf -L. -l ftpipex -o pipex

all: $(NAME)

clean:
	make clean -C library/libft
	make clean -C library/ft_printf
	rm -rf $(OBJS)

fclean: clean
	make fclean -C library/libft
	make fclean -C library/ft_printf
	rm -rf libftpipex.a
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re