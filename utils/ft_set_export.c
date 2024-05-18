
#include "../minishell.h"

void	set_export(t_data *ms, char **env)
{
	size_t	i;
	size_t	len;
	char	**head;

	head = env;
	while (*head)
		head++;
	len = head - env;
	ms->export = ft_calloc(sizeof(char **), len + 1);
	i = -1;
	while (++i < len)
		ms->export[i] = ft_strdup(env[i]);
}
