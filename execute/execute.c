#include "../minishell.h"

void	ft_close_all(t_data *ms)
{
	t_process	*process;

	process = ms->process;
	while (process)
	{
		if (ft_is_hd(process) && process->heredoc_fd[0] > 2)
			close(process->heredoc_fd[0]);
		if (process->fd[0] > 2)
			close(process->fd[0]);
		if (process->fd[1] > 2)
			close(process->fd[1]);
		process = process->next;
	}
}

void	wait_cmd(t_data *ms)
{
	t_process	*process;

	process = ms->process;
	ft_close_all(ms);
	while (process)
	{
		if (process->pid != -1)
		{
			waitpid(process->pid, &errno, 0);
			errno = WEXITSTATUS(errno);
		}
		process = process->next;
	}
}

void	ft_exec_builtin(t_data *ms, t_process *process)
{
	int	in;
	int	out;

	in = dup(0);
	out = dup(1);
	ft_change_in(ms, process);
	ft_change_out(ms, process);
	run_builtin(ms, process->execute);
	dup2(in, 0);
	dup2(out, 1);
	close(in);
	close(out);
}

void	ft_handle_fds(t_data *ms, t_process *process)
{
	if (ms->process_count > 1)
	{
		if (ft_is_hd(process))
		{
			dup2(process->heredoc_fd[0], 0);
			if (process->next != NULL)
				dup2(process->fd[1], 1);
		}
		else
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
	}
	ft_change_in(ms, process);
	ft_change_out(ms, process);
	ft_close_all(ms);
}

void	ft_start_process(t_data *ms, t_process *process)
{
	pid_t	pid;
	char	*path = NULL;

	pid = fork();
	if (pid == 0)
	{
		ft_handle_fds(ms, process);
		path = ft_getpath(ms, process->execute[0]);
		execve(path, process->execute, ms->env);
		free(path);
		ft_not_found_err(ms, process->execute[0]);
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
		return (ft_close_all(ms), FALSE);
	if (ft_isbuiltin(process->execute[0]) && ms->process_count == 1)
	{
		ft_exec_builtin(ms, process);
		process = process->next;
	}
	while (process)
	{
		ft_start_process(ms, process);
		process = process->next;
	}
	wait_cmd(ms);
	return(TRUE);
}
