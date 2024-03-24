#include "../minishell.h"

int	in_quotes(char *str, int i, char q)
{
	int	j;

	j = 0;
	if (str[i + j] == q)
	{
		j++;
		while (str[i + j] != q && str[i + j])
			j++;
		if (str[i + j + 1] != q && j % 2 == 0 && j != 1)
			j++;
	}
	return (j);
}

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

int	ft_handle_string(t_lexer **list, int i)
{
	int j;

	j = 0;
	while (ft_istoken(g_ms.line[i + j]) == 1 && g_ms.line[i + j])
	{
		if (ft_istoken(g_ms.line[i + j]) != 1)
			break ;
		j += in_quotes(g_ms.line, i + j, D_Q);
		j += in_quotes(g_ms.line, i + j, S_Q);
		if (ft_iswhitespace(g_ms.line[i + j]) > 0)
			break ;
		else if ((int)ft_strlen(g_ms.line) == i + j)
			break ;
		else
			j++;
	}
	if (!ft_token(ft_substr(g_ms.line, i, j), 0, list))
		return (-1);
	return (j);
}

void ft_tokenize(t_lexer **list)
{
	int i;
	int j;

	i = 0;
	while (g_ms.line[i])
	{
		j = 0;
		while (ft_iswhitespace(g_ms.line[i]))
			i++;
		if (ft_istoken(g_ms.line[i]) != 1)
			j += ft_handle_token(list, i);
		else
			j += ft_handle_string(list, i);
		if (j < 0)
			return ;
		i += j;
	}

}
