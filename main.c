#include "minishell.h"

void	ft_free_all(t_data *ms)
{
	ms->lexer_list = NULL;
	ms->process = NULL;
	ms->process_count = 0;
	ms->line = NULL;
}

void	ft_loop(t_data *ms, char **env)
{
	ft_init_ms(ms, env);
	while (TRUE)
	{
		char	*line;

		line = readline("minishell$: ");
		line = ft_strtrim(line, " ", "\t");
		ms->line = ft_strdup(line);
		free(line);
		add_history(ms->line);
		if (ft_lexer(ms) && ft_parser(ms))
		{
			ft_execute(ms);
		}
		ft_free_all(ms);
		ft_free_lexer(ms);
		ft_free_process(ms);
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
	ft_loop(&ms, env);

	return (0);
}
