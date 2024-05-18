#include "../minishell.h"

int	ft_ischild(t_data *ms)
{
	if (ms->child_pid == ft_child_pid())
		return(TRUE);
	return (FALSE);
}
