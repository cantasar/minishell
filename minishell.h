#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_data
{
	char			**env;
}	t_data;

extern t_data	g_mini;

//utils
void	set_env(char **env);

#endif