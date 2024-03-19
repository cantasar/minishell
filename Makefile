SRCS =	main.c\
		utils/init.c\
		utils/quotes.c\
		utils/ft_iswhitespace.c\
		utils/ft_istoken.c\
		lexer/lexer.c\
		lexer/lexer_utils.c\

CC = @gcc
NAME = minishell
CFLAGS = -Wall -Wextra -Werror
RM = @rm -rf
LIBFT	=	./libft

OBJS = $(SRCS:.c=.o)

READLINE = readline

all: $(READLINE) $(NAME)

$(READLINE):
	curl -O https://ftp.gnu.org/gnu/readline/readline-8.2.tar.gz
	tar -xvf readline-8.2.tar.gz
	cd readline-8.2 && ./configure --prefix=${PWD}/readline
	cd readline-8.2 && make install

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) ./libft/libft.a -L${PWD}/readline/lib  -I${PWD}/readline/include/ -lreadline
	make clean

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I${PWD}/readline/include/

fclean: clean
	$(RM) $(NAME)
	@rm -rf readline-8.2 readline-8.2.tar.gz
	make fclean -C $(LIBFT)
##	$(RM) ./readline

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

re: fclean all

.PHONY: all fclean clean re