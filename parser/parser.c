#include "../minishell.h"



//--------------PARSER PRINT FONKSİYONU--------------
void print_all_processes(t_process *process) {
    int i;

	printf("--------------PARSER--------------");
    while (process) {
        printf("\n\n");

        // Print execute commands
        printf("-- Commands --\n");
        i = 0;
        while (process->execute[i]) {
            printf("execute[%d]: %s\n", i, process->execute[i]);
            i++;
        }

        // Print redirects (handle potential null pointer)
        printf("\n-- Redirects --\n");
        if (process->redirects) {
            i = 0;
            while (process->redirects[i]) {
                printf("redirects[%d]: %s\n", i, process->redirects[i]);
                i++;
            }
        } else {
            printf("No redirects found.\n");
        }
        process = process->next;
		printf("\n--------------------------------\n");
    }
}
//--------------PRINT FONKSİYONU--------------


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

		t_process *p = ms->process;
		print_all_processes(p);


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