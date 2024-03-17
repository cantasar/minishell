#include "../minishell.h"

char	**set_env(char **env)
{
	char	**new_arr;
	size_t	i;

	i = 0;
	while (env[i] != NULL)
		i++;
	new_arr = ft_calloc(sizeof(char *), i + 1);
	if (!new_arr)
		return (NULL);
	i = 0;
	while (env[i] != NULL)
	{
		new_arr[i] = ft_strdup(env[i]);
		if (new_arr[i] == NULL)
		{
			free_arr(new_arr);
			return (new_arr);
		}
		i++;
	}
	return (new_arr);
}

void	set_path(void)
{
	int		i;
	char	*tmp;

	g_ms.path = ft_split(getenv("PATH"), ':');
	i = 0;
	while (g_ms.path[i])
	{
		if (ft_strncmp(&g_ms.path[i][ft_strlen(g_ms.path[i]) - 1],
			"/", 1) != 0)
		{
			tmp = ft_strjoin(g_ms.path[i], "/");
			free(g_ms.path[i]);
			g_ms.path[i] = tmp;
		}
		i++;
	}
}

void	init_ms(char **env_p)
{
	g_ms.env = set_env(env_p);
	set_path();
	g_ms.pwd = ft_strdup(getenv("PWD"));
	g_ms.oldpwd = ft_strdup(getenv("OLDPWD"));
}
