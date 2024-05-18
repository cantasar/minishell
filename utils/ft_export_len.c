#include "../minishell.h"

int	ft_env_len(t_data *ms)
{
	char	**env;

	env = ms->env;
	while (*env)
		env++;
	return (env - ms->env);
}

int	ft_export_len(t_data *ms)
{
	char	**export;

	export = ms->export;
	while (*export)
		export++;
	return (export - ms->export);
}
