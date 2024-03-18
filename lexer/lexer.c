#include "../minishell.h"

int	ft_handle_token(char *str, int i, t_lexer *lexer_list)
{
	t_tokens token;

	token = ft_istoken(str[i]);
	if (token == GREAT && ft_istoken(str[i + 1] == GREAT))
	{
		
	}
	
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
		if (ft_istoken(g_ms.line[i]))
			j += ft_handle_token(g_ms.line, i, &g_ms.lexer_list);
		// else
		// 	j += ft_handle_string();
		
		i += j;
	}
	
}