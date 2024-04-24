#include "../minishell.h"

void count_pipes()
{
	t_lexer	*tmp;

	tmp = g_ms.lexer_list;
	g_ms.count_pipes = 0;
	while (tmp)
	{
		if (tmp->token == 2)
			g_ms.count_pipes++;
		tmp = tmp->next;
	}
}