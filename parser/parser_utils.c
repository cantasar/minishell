#include "../minishell.h"

int	valid_op(char c)
{
	return ((c >= 'a' && c <= 'z') || \
			(c >= 'A' && c <= 'Z') || \
			(c >= '0' && c <= '9') || \
			(c == '_') || (c == '?'));
}

int ft_inquote(char *str) {
	int i = 0;
	int single_quote = TRUE;
	int double_quote = FALSE;

	while (str[i] && str[i] != DOLLAR) {
		if (str[i] == S_Q) {
			single_quote = double_quote;
		} else if (str[i] == D_Q) {
			double_quote = !double_quote;
		}
		i++;
	}
	if (!valid_op(*(ft_strchr(str, DOLLAR) + 1))) {
		return FALSE;
	}
	return (single_quote);
}