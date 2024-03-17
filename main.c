#include "minishell.h"

t_data g_ms;

void	minishell()
{
	char	*line;

	line = readline("minishell$: ");
	line = ft_strtrim(line, " ", "\t");
	g_ms.line = ft_strdup(line);
	if (!g_ms.line)
		exit(0);
	if (g_ms.line[0] == '\0')
		return ;
	add_history(g_ms.line);
	if (!check_quotes(g_ms.line))
	{
		printf("Quotes X\n");
	}

}

int main(int argc, char *argv[], char **env_p)
{
	if (argc != 1 || argv[1])
	{
		printf("Not accept arguments\n");
		exit(0);
	}
	init_ms(env_p);
	while (1)
		minishell();

	return (0);
}
