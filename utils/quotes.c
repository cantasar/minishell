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
	int s_q;
	int d_q;

	s_q = 0;
	d_q = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == 34)
			i += find_matching_quote(line, i, &d_q, D_Q);
		if (line[i] == 39)
			i += find_matching_quote(line, i, &s_q, S_Q);
		if ((int)ft_strlen(line) == i)
			break ;
	}
	//Toplam Quote sayısının çift olması gerekli kapanmış olması için
	if ((d_q > 0 && d_q % 2 != 0) || (s_q > 0 && s_q % 2 != 0))
		return (0);
	return (1);
}