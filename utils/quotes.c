#include "../minishell.h"

int find_matching_quote(char *line, int i, int *num_del, int del)
{
	int j;

	j = i + 1;
	*num_del += 1;
	while (line[j] && line[j] != del)
		j++;
	if (line[j] == del)
		*num_del += 1;
	return (j - i);
}

int check_quotes(char *line)
{
	int i;
	int s;
	int d;

	s = 0;
	d = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == 34)
			i += find_matching_quote(line, i, &d, D_Q);
		if (line[i] == 39)
			i += find_matching_quote(line, i, &s, S_Q);
		if ((int)ft_strlen(line) == i)
			break ;
	}
	if ((d > 0 && d % 2 != 0) || (s > 0 && s % 2 != 0))
		return (0);
	return (1);
}