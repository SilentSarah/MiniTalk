NAME = server
CLIENT = client
SRVSRC = server.c
CLSRC = client.c
ADDONS = ./sources/utils.c ./sources/ft_atoi.c ./sources/ft_bzero.c ./sources/ft_calloc.c ./sources/ft_itoa.c ./sources/ft_memset.c ./sources/ft_printf.c \
 ./sources/ft_putadress.c ./sources/ft_putbase_fd.c ./sources/ft_putbase_fdLower.c ./sources/ft_putchar_fd.c ./sources/ft_putnbr_fd.c ./sources/ft_putnbr_fd_unsigned.c \
 ./sources/ft_putstr_fd.c ./sources/ft_strdup.c ./sources/ft_strlcat.c ./sources/ft_strlcpy.c ./sources/ft_strlen.c
CC = gcc
FLAGS = -Wall -Wextra -Werror -I minitalk.h
LIB = libft.a

all: $(NAME) $(CLIENT) bonus

bonus: $(LIB)
	$(CC) $(FLAGS) server_bonus.c $(LIB) -o server_bonus
	$(CC) $(FLAGS) client_bonus.c $(LIB) -o client_bonus

$(NAME): $(LIB)
	$(CC) $(FLAGS) $(SRVSRC) $(LIB) -o $@
	$(CC) $(FLAGS) $(CLSRC) $(LIB) -o client

$(LIB): $(ADDONS:.c=.o)
	ar -rcs $@ $^

sources/%.o: sources/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf *.o
	rm -rf ./sources/*.o

fclean: clean
	rm -rf $(NAME)
	rm -rf $(CLIENT)
	rm -rf $(LIB)
	rm -rf server_bonus
	rm -rf client_bonus

re: fclean all
PHONY: clean fclean re all