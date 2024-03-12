#include "../minishell.h"

void	set_env(char **env)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (env[len])
		len++;
	g_mini.env = malloc(sizeof(char **) * len + 1);
	i = -1;
	while (++i < len)
		g_mini.env[i] = strdup(env[i]);
}
