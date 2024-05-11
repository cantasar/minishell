#include "../minishell.h"

void	ft_heredoc(t_data *ms)
{
	t_process *process;
	char **redirects;
	int i;
	int j = 0;

	process = ms->process;
	while (process)
	{
		redirects = process->redirects;
		i = 0;
		while (redirects[i] && !(ms->exit_signal))
		{
			if(redirects[i][0] == '<' && redirects[i][1] == '<')
			{
				printf("heredoc fouded at process %d\n", j);
			}
			i++;
		}
		process = process->next;
		j++;
	}
}

int	ft_execute(t_data *ms)
{
	ft_heredoc(ms);
	return(TRUE);
}