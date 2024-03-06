#include "minishell.h"

t_data g_mini;

void	init_ms(char **env_p)
{
	set_env(env_p);
}


int main(int argc, char *argv[], char **env_p)
{
	char	*input;

	(void)argc;
	(void)argv;
	init_ms(env_p);
	while (1) {
		input = readline("minishell: ");
		add_history(input);

		if (input == NULL)
			break;
	}

	return 0;
}
