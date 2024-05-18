#include "../minishell.h"

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
	g_signal = &ms->exit_signal;
	ms->env = ft_set_env(env);
	ms->path = NULL;
	ft_set_path(ms);
	set_export(ms, env);
	ms->lexer_list = NULL;
	ms->process = NULL;
	ms->process_count = 0;
	ms->err_flag = 0;
	ms->exit_signal = FALSE;
	ms->child_pid = ft_child_pid();
}
