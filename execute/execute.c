#include "../minishell.h"

void	close_heredoc_fd(t_process *process)
{
	if (ft_is_hd(process) && process->heredoc_fd[0] > 2)
		close(process->heredoc_fd[0]);
}

void	close_all_fd(t_data *ms)
{
	t_process	*process;

	process = ms->process;
	while (process)
	{
		close_heredoc_fd(process);
		if (process->fd[0] > 2)
			close(process->fd[0]);
		if (process->fd[1] > 2)
			close(process->fd[1]);
		process = process->next;
	}
}

void	get_all_inputs(t_process *process)
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
			// if (fd == -1)
			// 	return (no_file_err(redirects[i + 1]));
			dup2(fd, 0);
			close(fd);
		}
		else if (ft_isoperator(redirects[i]) == LESS_LESS)
			dup2(process->heredoc_fd[0], 0);
		i += 2;
	}
}

void	set_all_outputs(t_process *process)
{
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
				// if (!is_child())
				// 	return ;
				// else
				// 	exit(errno);
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
				// if (!is_child())
				// 	return ;
				// else
				// 	exit(errno);
			}
			dup2(fd, 1);
			close(fd);
		}
		i += 2;
	}
}

void	get_builtin(t_process *process)
{
	int	in;
	int	out;

	in = dup(0);
	out = dup(1);
	get_all_inputs(process);
	set_all_outputs(process);
	run_builtin(process->execute);
	dup2(in, 0);
	dup2(out, 1);
	close(in);
	close(out);
}

void	pipe_route(t_process *process)
{
	if (process->prev == NULL)
		dup2(process->fd[1], 1);
	else if (process->next == NULL)
		dup2(process->prev->fd[0], 0);
	else
	{
		dup2(process->prev->fd[0], 0);
		dup2(process->fd[1], 1);
	}
}

void	heredoc_route(t_process *process)
{
	dup2(process->heredoc_fd[0], 0);
	if (process->next != NULL)
		dup2(process->fd[1], 1);
}

void	cmd_route(t_data *ms, t_process *process)
{
	if (ms->process_count > 1)
	{
		if (ft_is_hd(process))
			heredoc_route(process);
		else
			pipe_route(process);
	}
	get_all_inputs(process);
	set_all_outputs(process);
	close_all_fd(ms);
}

void	run_cmd(t_data *ms, t_process *process)
{
	pid_t	pid;
	char	*path;

	pid = fork();
	if (pid == 0)
	{
		// signal(SIGQUIT, SIG_DFL);
		// signal(SIGINT, SIG_DFL);
		cmd_route(ms, process);
		path = get_path(process->execute[0]);
		execve(path, process->execute, ms->env);
		// command_err(process->execute[0]);
		exit(errno);
	}
	else
		process->pid = pid;
}

int	ft_execute(t_data *ms)
{
	t_process	*process;

	process = ms->process;
	if (!process)
		return (FALSE);
	ft_heredoc(ms);
	if (ms->exit_signal)
		return (close_all_fd(ms), FALSE);
	if (ft_isbuiltin(process->execute[0]) && ms->process_count == 1)
	{
		printf("builtin\n");
		// get_builtin(process);
		// process = process->next;
	}
	while (process)
	{
		run_cmd(ms, process);
		process = process->next;
	}
	// wait_cmd();
	return(TRUE);
}
