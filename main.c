#include "minishell.h"

t_data g_ms;

void	ft_loop(t_data *ms)
{
	while (TRUE)
	{
		char	*line;

		line = readline("minishell$: ");
		line = ft_strtrim(line, " ", "\t");
		ms->line = ft_strdup(line);
		free(line);
		if (ft_lexer(ms) && ft_parser(ms))
		{
			continue;
		}
		else
		{
			printf(" -exec edilmedi \n   -free \n -loop \n");
		}
		
		add_history(ms->line);
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

	ft_init_ms(&ms, env);
	ft_loop(&ms);

	return (0);
}
