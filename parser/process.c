#include "../minishell.h"

t_process	*ft_init_process(void)
{
	t_process	*process;

	process = ft_calloc(sizeof(t_process), 1);
	pipe(process->fd);
	process->pid = -1;
	process->execute = ft_calloc(sizeof(char *), 1);
	process->redirects = ft_calloc(sizeof(char *), 1);
	process->prev = NULL;
	process->next = NULL;
	return (process);
}

void	ft_process_addback(t_process **process, t_process *new_process)
{
	t_process	*process_list;

	process_list = *process;
	if (!(process_list))
		*process = new_process;
	else
	{
		while (process_list->next)
			process_list = process_list->next;
		process_list->next = new_process;
		new_process->prev = process_list;
	}
}
