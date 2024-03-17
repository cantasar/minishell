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

typedef struct s_data
{
	char	*line;
	char	**env;
	char	**path;
	char	*pwd;
	char	*oldpwd;
}	t_data;

extern t_data	g_ms;

//utils
void	init_ms(char **env_p);
int check_quotes(char *line);

#endif