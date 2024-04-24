#include "../minishell.h"

int	parser()
{
	count_pipes(g_ms, g_ms.lexer_list);

	printf("count_pipes: %d\n", g_ms.count_pipes);

	return (1);
}