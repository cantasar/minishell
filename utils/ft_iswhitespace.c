#include "../minishell.h"

int	ft_iswhitespace(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}