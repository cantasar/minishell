SRCS =	main.c\
		utils/ft_init.c\
		utils/ft_iswhitespace.c\
		utils/ft_isoperator.c\
		utils/ft_istoken.c\
		utils/ft_add_arr.c\
		utils/ft_in_squote.c\
		utils/ft_isvalid.c\
		utils/ft_is_hd.c\
		utils/ft_ischild.c\
		utils/ft_child_pid.c\
		utils/ft_getenv.c\
		utils/ft_getpath.c\
		utils/ft_strcmp.c\
		utils/ft_check_flag.c\
		utils/ft_export_len.c\
		utils/ft_export_check.c\
		utils/ft_print_export.c\
		utils/ft_export_pos.c\
		utils/ft_set_export.c\
		utils/ft_isinclude.c\
		utils/ft_swap.c\
		lexer/ft_lexer.c\
		lexer/ft_lexer_utils.c\
		lexer/ft_syntax_check.c\
		lexer/ft_tokenize.c\
		parser/ft_parser.c\
		parser/ft_parser_utils.c\
		parser/ft_process.c\
		parser/ft_quotes.c\
		execute/ft_execute.c\
		execute/ft_execute_utils.c\
		execute/ft_heredoc.c\
		builtin/ft_builtin.c\
		builtin/ft_echo.c\
		builtin/ft_cd.c\
		builtin/ft_env.c\
		builtin/ft_exit.c\
		builtin/ft_export.c\
		builtin/ft_unset.c\
		builtin/ft_pwd.c\
		error/ft_error.c\
		free/ft_free.c\

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

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I${PWD}/readline/include/

fclean: clean
	$(RM) $(NAME)
	@rm -rf readline-8.2 readline-8.2.tar.gz
	make fclean -C $(LIBFT)
	$(RM) ./readline

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

re: fclean all

.PHONY: all fclean clean re