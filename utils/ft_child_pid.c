#include "../minishell.h"

int	ft_child_pid(void)
{
	int	pid;

	pid = fork();
	if (!pid)
	{
		exit(1);
	}
	return (pid);
}
