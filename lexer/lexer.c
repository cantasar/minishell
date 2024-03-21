#include "../minishell.h"

int	lexer()
{
	ft_tokenize(&g_ms.lexer_list);


	//lexerlist print
	while (g_ms.lexer_list && g_ms.lexer_list->next)
	{
		printf("token type: %d\n", g_ms.lexer_list->token);
		printf("token str: %s\n", g_ms.lexer_list->str);
		printf("------\n");
		g_ms.lexer_list = g_ms.lexer_list->next;
	}
		printf("token type: %d\n", g_ms.lexer_list->token);
		printf("token str: %s\n", g_ms.lexer_list->str);

	return(1);
}