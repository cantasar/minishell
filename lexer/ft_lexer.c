#include "../minishell.h"

int	ft_lexer(t_data *ms)
{
	if (ft_empty_line(ms) || ft_strlen(ms->line) == 0)
		return (FALSE);
	else if (ft_check_pipes(ms) == TRUE)
		return (FALSE);
	else if (ft_check_quotes(ms->line) == TRUE)
		return (FALSE);
	ft_tokenize(ms, &ms->lexer_list);
	return (TRUE);
}
