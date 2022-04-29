
NAME = Minitalk.a
OBJ = $(SRC:.c=.o)
SRC = ft_printf/ft_putnbr.c\
ft_printf/ft_hexconv.c\
ft_printf/ft_putstr.c \
ft_printf/ft_putchar.c \
ft_printf/ft_printf.c \
ft_printf/ft_print_str.c \
utils/ft_isalpha.c \
utils/ft_atoi.c \

CC = gcc -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
%.o: %.c 
	$(CC) -c $< -o $@
clean: 
	$(RM) $(OBJ)
fclean:
	$(RM) $(NAME) $(OBJ) server client
re: fclean all

server:
	gcc server.c $(OBJ) -o server

client:
	gcc client.c $(OBJ) -o client
.PHONY: all, clean, fclean,