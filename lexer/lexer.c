#include "../minishell.h"

int	ft_handle_token(char *str, int i, t_lexer *lexer_list)
{
	int token;
	(void)lexer_list;
	(void)str;
	(void)i;

	token = ft_istoken(g_ms.line[i]);
	if (token == 2 && (ft_istoken(g_ms.line[i + 1]) == 2))
	{
		ft_add_list(NULL, GREAT_GREAT, &lexer_list);
		return(2);
	}
	else if (token == 4 && (ft_istoken(g_ms.line[i + 1]) == 4))
	{
		ft_add_list(NULL, LESS_LESS, &lexer_list);
		return(2);
	}
	else if (token == 1)
		ft_add_list(NULL, PIPE, &lexer_list);
	else if (token == 2)
		ft_add_list(NULL, GREAT, &lexer_list);
	else if (token == 4)
		ft_add_list(NULL, LESS, &lexer_list);
	
	while (g_ms.lexer_list->next)
	{
		printf("%d\n", g_ms.lexer_list->token);
		//g_ms.lexer_list = g_ms.lexer_list->next;
	}
	

	return(1);
}

int	lexer()
{
	int i;
	int j;

	i = 0;
	while (g_ms.line[i])
	{
		j = 0;
		while(ft_iswhitespace(g_ms.line[i]))
			i++;
		if (ft_istoken(g_ms.line[i]) != 0)
		{
			j += ft_handle_token(g_ms.line, i, g_ms.lexer_list);
			i += j;
		}
		else
			i++;
		
	}
	return(1);
}