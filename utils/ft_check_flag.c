#include "../minishell.h"

void	ft_check_flag(t_data *ms)
{
	if (ms->err_flag == 1)
	{
		errno = 1;
		ms->err_flag = 0;
	}
}
