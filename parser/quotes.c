#include "../minishell.h"

void	push_new_str(char **new_str, char *str)
{
	char	*tmp;

	if (!(*new_str))
	{
		*new_str = ft_strdup(str);
		free(str);
		return ;
	}
	tmp = *new_str;
	*new_str = ft_strjoin(*new_str, str);
	free(tmp);
	free(str);
}

char	*ft_clean_quote_with_type(char *str, int *pos, char type)
{
	int		first;
	char	*new_str;

	(*pos)++;
	first = *pos;
	while (str[*pos] && str[*pos] != type)
		(*pos)++;
	new_str = ft_substr(str, first, *pos - first);
	if (str[*pos])
		(*pos)++;
	return (new_str);
}

static char	*get_str(char *str, int	*pos)
{
	int	first;

	first = *pos;
	while (str[*pos] && str[*pos] != D_Q && str[*pos] != S_Q)
		(*pos)++;
	return (ft_substr(str, first, *pos - first));
}

char	*ft_clean_quote(char *str)
{
	int		i;
	char	*data;
	char	*result;

	i = 0;
	result = NULL;
	// str = ft_check_dollar(str);
	while (str[i])
	{
		if (str[i] == D_Q)
			data = ft_clean_quote_with_type(str, &i, D_Q);
		else if (str[i] == S_Q)
			data = ft_clean_quote_with_type(str, &i, S_Q);
		else
			data = get_str(str, &i);
		push_new_str(&result, data);
	}
	//free(str);
	return (result);
}
