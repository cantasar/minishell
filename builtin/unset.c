#include "../minishell.h"

void	remove_env(t_data *ms, char *data)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	j = 0;
	new_env = ft_calloc(sizeof(char *), ft_env_len(ms) + 1);
	while (ms->env[i])
	{
		if (ft_strncmp(ms->env[i], data, ft_strlen(data)))
		{
			new_env[j] = ft_strdup(ms->env[i]);
			j++;
		}
		i++;
	}
	new_env[j] = 0;
	ft_free_arr(ms->env);
	ms->env = new_env;
}

void	remove_export(t_data *ms, char *data)
{
	int		i;
	int		j;
	char	**new_export;

	i = 0;
	j = 0;
	new_export = ft_calloc(sizeof(char *), ft_export_len(ms) + 1);
	while (ms->export[i])
	{
		if (ft_strncmp(ms->export[i], data, ft_strlen(data)))
		{
			new_export[j] = ft_strdup(ms->export[i]);
			j++;
		}
		i++;
	}
	new_export[j] = 0;
	ft_free_arr(ms->export);
	ms->export = new_export;
}

void	ft_unset(t_data *ms, char **input)
{
	char	*data;

	input++;
	while (*input)
	{
		if (ft_strchr(*input, '='))
		{
			data = ft_strjoin(*input, "=");
			remove_env(ms, data);
			remove_export(ms, data);
		}
		else
		{
			data = ft_strdup(*input);
			remove_export(ms, data);
			remove_env(ms, data);
		}
		free(data);
		input++;
	}
	ft_set_path(ms);
	if (ft_ischild(ms))
		exit (EXIT_SUCCESS);
}
