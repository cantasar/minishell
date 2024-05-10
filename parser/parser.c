#include "../minishell.h"

int	ft_fill_process(t_data *ms, t_lexer **lexer_list, t_process *process)
{
	char		*data;

	if ((*lexer_list)->token == STRING)
	{
		data = ft_clean_quote(ms, (*lexer_list)->str);
		process->execute = ft_add_arr(process->execute, data);
	}
	else
	{
		data = ft_clean_quote(ms, (*lexer_list)->str);
		process->redirects = ft_add_arr(process->redirects, data);
		*lexer_list = (*lexer_list)->next;
		if (!(*lexer_list) || (*lexer_list)->token != STRING)
		{
			if (!(*lexer_list))
				ft_token_err(0);
			else
				ft_token_err((*lexer_list)->token);
			return (FALSE);
		}
		data = ft_clean_quote(ms, (*lexer_list)->str);
		process->redirects = ft_add_arr(process->redirects, data);
	}
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
		if (ft_fill_process(ms, &list, process) == FALSE)
			return (FALSE);
		list = list->next;
	}
	return (TRUE);
}

int	ft_parser(t_data *ms)
{

	t_lexer		*token;
	t_process	*process;
	int			err;

	process = NULL;
	token = ms->lexer_list;
	err = ft_new_process(ms, token, process);
	if (err == FALSE)
		return (FALSE);


			//print **execute
			printf("\n\n");
			printf("--PARSER--\n");
			int i = 0;
			while (ms->process->execute[i])
			{
				printf("process->execute[%d]-> %s\n", i, ms->process->execute[i]);
				i++;
			}
			
			// //eğer pipe yoksa bu kısım yazdırılırken seg fault alır
			// ms->process = ms->process->next;
			// printf("\n\n");
			// i=0;
			// while (ms->process->execute[i])
			// {
			// 	printf("process->execute[%d]-> %s\n", i, ms->process->execute[i]);
			// 	i++;
			// }

			printf("\n\n");

			//print **redirects
			i = 0;
			while (ms->process->redirects[i])
			{
				printf("process->redirects[%d]-> %s\n", i, ms->process->redirects[i]);
				i++;
			}


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