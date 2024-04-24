#include "../minishell.h"

int	lexer()
{
	ft_tokenize(&g_ms.lexer_list);


	//lexerlist print
	t_lexer	*tmp;

	tmp = g_ms.lexer_list;
	while (tmp)
	{
		printf("token type: %d\n", tmp->token);
		printf("token str: %s\n", tmp->str);
		printf("------\n");
		tmp = tmp->next;
	}
		printf("\n");

	return(1);
}