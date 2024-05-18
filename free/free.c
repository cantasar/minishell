#include "../minishell.h"

void	ft_free_lexer(t_data *ms)
{
	t_lexer		*tmp;
	t_lexer		*lexer_list;

	// lexer_list = ms->lexer_list;
	// while (lexer_list)
	// {
	// 	free(lexer_list->str);
	// 	lexer_list = lexer_list->next;
	// }
	lexer_list = ms->lexer_list;
	while (lexer_list)
	{
		tmp = lexer_list;
		lexer_list = lexer_list->next;
		free(tmp);
	}
}

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_process(t_data *ms)
{
	t_process	*tmp;
	t_process	*process;

	process = ms->process;
	if (!process)
		return ;
	while (process)
	{
		ft_free_arr(process->execute);
		ft_free_arr(process->redirects);
		tmp = process;
		process = process->next;
		free(tmp);
	}
}
