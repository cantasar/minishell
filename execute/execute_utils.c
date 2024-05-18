#include "../minishell.h"

void	ft_change_in(t_data *ms, t_process *process)
{
	int		i;
	int		fd;
	char	**redirects;

	i = 0;
	redirects = process->redirects;
	while (redirects[i])
	{
		if (ft_isoperator(redirects[i]) == LESS)
		{
			fd = open(redirects[i + 1], O_RDONLY);
			if (fd == -1)
				return (ft_nofile_err(ms, redirects[i + 1]));
			dup2(fd, 0);
			close(fd);
		}
		else if (ft_isoperator(redirects[i]) == LESS_LESS)
			dup2(process->heredoc_fd[0], 0);
		i += 2;
	}
}

void	ft_change_out(t_data *ms, t_process *process)
{
	(void)ms;

	int		i;
	int		fd;
	char	**redirects;

	i = 0;
	fd = 0;
	redirects = process->redirects;
	while (redirects[i])
	{
		if (ft_isoperator(redirects[i]) == GREAT)
		{
			fd = open(redirects[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
			if (fd == -1)
			{
				perror("minishell");
				if (!ft_ischild(ms))
					return ;
				else
					exit(errno);
			}
			dup2(fd, 1);
			close(fd);
		}
		else if (ft_isoperator(redirects[i]) == GREAT_GREAT)
		{
			fd = open(redirects[i + 1], O_CREAT | O_WRONLY | O_APPEND, 0777);
			if (fd == -1)
			{
				perror("minishell");
				if (!ft_ischild(ms))
					return ;
				else
					exit(errno);
			}
			dup2(fd, 1);
			close(fd);
		}
		i += 2;
	}
}
