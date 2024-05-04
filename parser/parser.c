#include "../minishell.h"

int	ft_fill_process(t_data *ms, t_lexer **lexer_list, t_process *process)
{
	char		*data;
	(void)process;
	(void)ms;

	if ((*lexer_list)->token == STRING)
	{
		data = ft_clean_quote((*lexer_list)->str);
		printf("q removed->%s\n", data);
		process->execute = ft_add_arr(process->execute, data);

		




	}
		int i = 0;
		while (process->execute[i])
		{
			printf("process->execute[%d]-> %s\n", i, process->execute[i]);
			i++;
		}
	// else
	// {
	// 	data = ft_clean_quote((*lexer_list)->str);
	// 	process->redirects = push_array(process->redirects, data);
	// 	*lexer_list = (*lexer_list)->next;
	// 	if (!(*lexer_list) || (*lexer_list)->token != STRING) // tokendan sonra string gelmeme durumu -> abc <<< asd
	// 	{
	// 		if (!(*lexer_list))
	// 			ft_token_err(1);
	// 		else
	// 			ft_token_err((*lexer_list)->token);
	// 		ft_free_lexer(ms);
	// 		return (FALSE);
	// 	}
	// 	data = ft_clean_quote((*lexer_list)->str);
	// 	process->redirects = push_array(process->redirects, data);
	// }
	return (TRUE);
}

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
		if (!ft_fill_process(ms, &list, process))
			return (FALSE);
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
	printf("process sayısı --> %d\n", ms->process_count);
	return (TRUE);
}






	// t_process	*tmp;
	// tmp = ms->process;
	// while (tmp)
	// {
	// 	printf("exec str0: %s\n", tmp->execute[0]);
	// 	printf("exec str1: %s\n", tmp->execute[1]);
	// 	printf("------\n");
	// 	tmp = tmp->next;
	// }
	// printf("\n");