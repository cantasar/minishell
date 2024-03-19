#ifndef MINISHELL_H
# define MINISHELL_H

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

# define TRUE 1
# define FALSE 0

# define D_Q '"'
# define S_Q '\''

typedef enum s_tokens
{
	PIPE = 1,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
}	t_tokens;

typedef struct s_lexer
{
	char			*str;
	t_tokens		token;
	int				i;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

typedef struct s_data
{
	char	*line;
	char	**env;
	char	**path;
	char	*pwd;
	char	*oldpwd;
	t_lexer	*lexer_list;
}	t_data;

extern t_data	g_ms;

//utils
void		ft_init_ms(char **env_p);
int 		ft_check_quotes(char *line);

int			ft_iswhitespace(char c);
int	ft_istoken(char c);

//Lexer
int	lexer();
void	ft_add_list(char *str, t_tokens token, t_lexer **list);


#endif