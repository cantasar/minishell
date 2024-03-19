#include "../minishell.h"

int	ft_istoken(char c)
{
	if (c == '|')
		return (PIPE);
	else if (c == '<')
		return (LESS);
	else if (c == '>')
		return (GREAT);
	else
		return (0);
}