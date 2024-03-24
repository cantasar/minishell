#include "../minishell.h"

int	ft_istoken(int c)
{
	if (c == '|')
		return (2);
	else if (c == '<')
		return (3);
	else if (c == '>')
		return (5);
	else
		return (1);
}
