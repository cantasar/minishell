#include "minishell.h"

int main(int argc, char *argv[], char **env_p)
{
	char	*input;

	(void)argc;
	(void)argv;
	while (1) {
		input = readline("minishell: ");

		if (input == NULL)
			break; // Ctrl+D veya EOF ile çıkış yap

	}

	return 0;
}
