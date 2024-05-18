#include "../minishell.h"

void	print_export(t_data *ms)
{
	char	**export;

	export = ms->export;
	while (*export)
	{
		printf("declare -x %s\n", *export);
		export++;
	}
	if (ft_ischild(ms))
		exit (EXIT_SUCCESS);
}
