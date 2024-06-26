/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:43:15 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 18:25:29 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	process = NULL;
	token = ms->lexer_list;
	if (ft_new_process(ms, token, process) == FALSE)
		return (FALSE);
	return (TRUE);
}
