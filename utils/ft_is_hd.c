#include "../minishell.h"

int	ft_is_hd(t_process *process)
{
	int	i;

	i = 0;
	while (process->redirects[i])
	{
		if (ft_isoperator(process->redirects[i]) == LESS_LESS)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
