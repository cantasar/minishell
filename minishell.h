#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <dirent.h>

# include <errno.h>

# define TRUE 1
# define FALSE 0



# define D_Q '"'
# define S_Q '\''
# define DOLLAR '$'

enum e_builtin_types
{
	CD = 1,
	ENV,
	PWD,
	ECHO,
	EXIT,
	UNSET,
	EXPORT
};

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
	char		**export;
	char		*pwd;
	char		*oldpwd;
	int			process_count;
	int			child_pid;
	int			exit_signal;
	t_lexer		*lexer_list;
	t_process	*process;
}	t_data;

//utils
void		ft_init_ms(t_data *ms, char **env);
char		*ft_getenv(t_data *ms, char *str);
void		ft_set_path(t_data *ms);
int 		ft_check_quotes(char *line);
int			ft_iswhitespace(char c);
int			ft_isoperator(char *str);
int			ft_istoken(int c);
int			ft_isvalid(char c);
int			ft_is_hd(t_process *process);
int			ft_ischild(t_data *ms);
char		**ft_add_arr(char **arr, char *new);
int			ft_in_squote(char *str);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_getpath(t_data *ms, char *cmd);
int			ft_child_pid(void);

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

char	*ft_clean_quote(t_data *ms, char *str);

char	*ft_parse_dollar(t_data *ms, char *str);

//execute

int		ft_execute(t_data *ms);

void	ft_change_in(t_data *ms, t_process *process);
void	ft_change_out(t_data *ms, t_process *process);

	//heredoc
	void	ft_heredoc(t_data *ms);



//builtin
int		ft_isbuiltin(char *command);
void	run_builtin(char **execute);

//error
void	ft_token_err(int type);
void	ft_nofile_err(t_data *ms, char *str);
void	ft_not_found_err(t_data *ms, char *str);

//free
void	ft_free_lexer(t_data *ms);
void	ft_free_process(t_data *ms);


#endif