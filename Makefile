SRCS =	minishell.c\
		lexer/lexer.c\
		lexer/tokenize.c\
		lexer/t_token_utils.c\
		utils/set.c\
		utils/ft_calloc.c\
		utils/ft_str.c\
		utils/is.c\

CC = @gcc
NAME = minishell
CFLAGS = -Wall -Wextra -Werror
RM = @rm -rf

OBJS = $(SRCS:.c=.o)

READLINE = readline

all: $(READLINE) $(NAME)

$(READLINE):
	curl -O https://ftp.gnu.org/gnu/readline/readline-8.2.tar.gz
	tar -xvf readline-8.2.tar.gz
	cd readline-8.2 && ./configure --prefix=${PWD}/readline
	cd readline-8.2 && make install

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) -L${PWD}/readline/lib  -I${PWD}/readline/include/ -lreadline

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I${PWD}/readline/include/

fclean: clean
	$(RM) $(NAME)
	@rm -rf readline-8.2 readline-8.2.tar.gz
##	$(RM) ./readline

clean:
	$(RM) $(OBJS)

re: fclean all

.PHONY: all fclean clean re