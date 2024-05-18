#include "../minishell.h"

int	check_export(t_data *ms, char *str)
{
	char	**export;

	export = ms->export;
	while (*export)
	{
		if (ft_strcmp(*export, str) || export_pos(str, *export))
			return (FALSE);
		export++;
	}
	return (TRUE);
}

int	export_check_char(char *str)
{
	int	i;

	i = 1;
	if (!ft_isalpha(str[0]))
		return (FALSE);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_env(t_data *ms, char *str)
{
	char	*head;

	head = ft_strchr(str, '=');
	if (!head)
	{
		if (check_export(ms, str))
		{
			if (export_check_char(str))
				add_export(ms, str);
			else
				export_err(ms, str);
		}
		return (FALSE);
	}
	if (head == str)
		return (FALSE);
	while (*str)
	{
		if (ft_iswhitespace(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}
