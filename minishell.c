#include "minishell.h"

t_data g_mini;

void	init_ms(char *input, char **env_p)
{
	set_env(env_p);
	if (!lexer(input))
		return ;
	
}

int main(int argc, char *argv[], char **env_p)
{
	char	*input;

	(void)argc;
	(void)argv;
	while (1) {
		input = readline("minishell: ");
		add_history(input);
		if (input == NULL)
			break;
		else
		{
			init_ms(input, env_p);
		}
	}

	return 0;
}
