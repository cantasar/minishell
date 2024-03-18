#include "minishell.h"

t_data g_ms;

void	ft_minishell()
{
	char	*line;

	line = readline("minishell$: ");
	line = ft_strtrim(line, " ", "\t");
	g_ms.line = ft_strdup(line);
	if (!g_ms.line)
		exit(1);
	if (g_ms.line[0] == '\0')
		return ;
	add_history(g_ms.line);
	if (!ft_check_quotes(g_ms.line))
		return ;

}

int main(int argc, char *argv[], char **env_p)
{
	if (argc != 1 || argv[1])
	{
		printf("Not accept arguments\n");
		exit(0);
	}
	ft_init_ms(env_p);
	while (1)
		ft_minishell();

	return (0);
}

//https://www.notion.so/minishell-f32cac3191af4f458fb5a13d41f04131?pvs=4
