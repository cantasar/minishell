#include "../minishell.h"

void	swap_export(t_data *ms, int pos, char *input)
{
	char	*temp;

	temp = ms->export[pos];
	ms->export[pos] = ft_strdup(input);
	free(temp);
}

void	swap_env(t_data *ms, int pos, char *input)
{
	char	*temp;

	temp = ms->env[pos];
	ms->env[pos] = ft_strdup(input);
	free(temp);
}
