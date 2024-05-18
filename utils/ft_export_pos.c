#include "../minishell.h"

int	export_pos(char *str, char *export)
{
	int		pos;
	char	*tmp;

	pos = 0;
	while (export[pos] && export[pos] != '=')
		pos++;
	tmp = ft_substr(export, 0, pos);
	if (ft_strcmp(tmp, str))
	{
		free (tmp);
		return (TRUE);
	}
	free (tmp);
	return (FALSE);
}
