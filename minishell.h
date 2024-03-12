#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

# define TRUE 1
# define FALSE 0

# define D_Q '"'
# define S_Q '\''

enum e_ttype
{
	PIPE = 1,
	STRING,
	HERE_DOC,
	RED_INPUT,
	RED_APPEND,
	RED_OUTPUT
};

typedef struct s_token
{
	char			*str;
	enum e_ttype	type;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_data
{
	char			**env;
	t_token			*tokens;
}	t_data;

extern t_data	g_mini;

//lexer
int	lexer(char *input);
void	tokenize(char *s);

t_token	*init_ttoken(char *str, enum e_ttype type);
void	token_add(t_token **token, t_token *new);

//utils
void	set_env(char **env);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t n);

char	*ft_substr(char const *str, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);

int	is_space(char s);
int	is_operator(char *str);


#endif