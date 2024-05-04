#include "../minishell.h"

int	ft_new_process(t_data *ms, t_lexer *list, t_process *process)
{
	while (list)
	{
		if (list->token == PIPE || list->prev == NULL)
		{
			if (list->token == PIPE)
				list = list->next;
			process = ft_init_process();
			ft_process_addback(&ms->process, process);
			ms->process_count++;
		}
		if (!list)
		{
			ft_token_err(PIPE);
			break ;
		}
		// if (!append_arguments(&list, process))
		// 	return (FALSE);
		list = list->next;
	}
	return (TRUE);
}

int	ft_parser(t_data *ms)
{
	printf("parser\n");

	t_lexer		*token;
	t_process	*process;
	int			err;

	process = NULL;
	token = ms->lexer_list;
	err = ft_new_process(ms, token, process);
	if (err == FALSE)
		return (FALSE);
	printf("-->%d\n", ms->process_count);
	// free_token();
	return (TRUE);
}