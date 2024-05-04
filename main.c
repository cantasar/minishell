#include "minishell.h"

t_data g_ms;

void	ft_loop(t_data *ms, char **env)
{
	while (TRUE)
	{
		char	*line;

		line = readline("minishell$: ");
		line = ft_strtrim(line, " ", "\t");
		ms->line = ft_strdup(line);
		free(line);
		ft_init_ms(ms, env);
		if (ft_lexer(ms) && ft_parser(ms))
		{
			printf("execute\n-\n\n");
		}
		else
		{
			printf(" -exec edilmedi \n   -free \n -loop \n\n\n");
		}
		add_history(ms->line);
		ft_free_lexer(ms);
	}
}

int main(int argc, char *argv[], char **env)
{
	t_data ms;

	if (argc != 1 || argv[1])
	{
		printf("Not accept arguments\n");
		exit(EXIT_SUCCESS);
	}

	// ft_init_ms(&ms, env);
	ft_loop(&ms, env);

	return (0);
}
