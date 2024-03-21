#include "../minishell.h"

int	ft_handle_token(t_lexer **list, int i)
{
	t_tokens token;

	token = ft_istoken(g_ms.line[i]);
	if (token == GREAT && ft_istoken(g_ms.line[i + 1]) == GREAT)
	{
		if (!ft_token(NULL, GREAT_GREAT, list))
			return (-1);
		return (2);
	}
	else if (token == LESS && ft_istoken(g_ms.line[i + 1]) == LESS)
	{
		if (!ft_token(NULL, LESS_LESS, list))
			return (-1);
		return (2);
	}
	else if (token)
	{
		if (!ft_token(NULL, token, list))
			return (-1);
		return (1);
	}
	return (0);
}

//quotes kontrolü eklenicek
int	ft_handle_string(t_lexer **list, int i)
{
	int j;

	j = 0;
	while (ft_istoken(g_ms.line[i + j]) == 1 && g_ms.line[i + j])
	{
		if (ft_iswhitespace(g_ms.line[i + j]))
			break ;
		else if ((int)ft_strlen(g_ms.line) == i + j)
			break ;
		else
			j++;
	}
	ft_token(ft_substr(g_ms.line, i, j), STRING, list);
	return (j);
}

void ft_tokenize(t_lexer **list)
{
	int i;
	t_tokens token;

	i = 0;
	while (g_ms.line[i])
	{
		while (ft_iswhitespace(g_ms.line[i]))
			i++;
		token = ft_istoken(g_ms.line[i]);
		if (token != 1)
			i += ft_handle_token(list, i);
		else if (token == 1)
			i += ft_handle_string(list, i);
		else
			i++;
	}
}
