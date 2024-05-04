#include "../minishell.h"

char	**ft_add_arr(char **arr, char *new)
{
	int		i;
	int		len;
	char	**new_arr;

	i = 0;
	len = 0;
	while (arr && arr[len])
		len++;
	new_arr = ft_calloc(sizeof(char *), len + 2);
	while (i < len)
	{
		new_arr[i] = arr[i];
		i++;
	}
	new_arr[i] = new;
	free(arr);
	return (new_arr);
}