#include "../minishell.h"

//yeni bir char** array oluşturup env yi içine kopyalıyor
char	**ft_set_env(char **env)
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

void	ft_set_path(t_data *ms)
{
	char	*path;

	if (ms->path)
		free_arr(ms->path);
	path = ft_getenv(ms, "PATH");
	if (!(*path))
		ms->path = NULL;
	else
		ms->path = ft_split(path, ':');
	free(path);
}

void	ft_init_ms(t_data *ms, char **env)
{
	ms->env = ft_set_env(env);
	ms->path = NULL;
	ft_set_path(ms);
	ms->pwd = ft_strdup(getenv("PWD"));
	ms->oldpwd = ft_strdup(getenv("OLDPWD"));
	ms->lexer_list = NULL;
	ms->process = NULL;
	ms->process_count = 0;
	ms->exit_signal = FALSE;
	ms->child_pid = ft_child_pid();

	// //print env
	// printf(("\n"));
	// int i = 0;
	// while (ms->env[i])
	// 	printf("%s\n", ms->env[i++]);
	// printf(("\n"));

	// //print path
	// printf(("\n"));
	// i = 0;
	// while (ms->path[i])
	// 	printf("%s\n", ms->path[i++]);
	// printf(("\n"));
	
}
