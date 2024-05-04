#ifndef MINISHELL_H
# define MINISHELL_H

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

# include <errno.h>

# define TRUE 1
# define FALSE 0



# define D_Q '"'
# define S_Q '\''

typedef enum e_ttype
{
	STRING = 1,
	PIPE,
	LESS,
	LESS_LESS,
	GREAT,
	GREAT_GREAT
} t_tokens;

typedef struct s_lexer
{
	char			*str;
	t_tokens		token;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

typedef struct s_process
{
	pid_t				pid;
	int					fd[2];
	int					heredoc_fd[2];
	char				**execute;
	char				**redirects;
	struct s_process	*prev;
	struct s_process	*next;
}	t_process;

typedef struct s_data
{
	char		*line;
	char		**env;
	char		**path;
	char		*pwd;
	char		*oldpwd;
	int			process_count;
	t_lexer		*lexer_list;
	t_process	*process;
}	t_data;

//utils
void	ft_init_ms(t_data *ms, char **env);
int 		ft_check_quotes(char *line);

int			ft_iswhitespace(char c);
int			ft_istoken(int c);

//Lexer
int	ft_lexer(t_data *ms);

void ft_tokenize(t_data *ms, t_lexer **list);

int	ft_token(char *str, t_tokens token, t_lexer **list);
t_lexer	*ft_new_token(char *str, t_tokens token);
void	ft_token_addback(t_lexer **list, t_lexer *last);

int	ft_empty_line(t_data *ms);
int	ft_check_pipes(t_data *ms);
int	ft_check_operator(char *str);

//parser

int	ft_parser(t_data *ms);

t_process	*ft_init_process(void);
void	ft_process_addback(t_process **process, t_process *new_process);

//error
void	ft_token_err(int type);


#endif