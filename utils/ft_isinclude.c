/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinclude.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:43:48 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 17:43:49 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_include_env(t_data *ms, char *str)
{
	int		i;
	int		j;
	char	**env;

	i = 0;
	env = ms->env;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && str[j])
		{
			if (str[j] == '=' && env[i][j] == '=')
				return (i);
			if (str[j] != env[i][j])
				break ;
			j++;
		}
		i++;
	}
	return (-1);
}

int	is_include_export(t_data *ms, char *str)
{
	int		i;
	int		j;
	char	**export;

	i = 0;
	export = ms->export;
	while (export[i])
	{
		j = 0;
		while (export[i][j] && str[j])
		{
			if (str[j] == '=' && export[i][j] == '=')
				return (i);
			if (str[j] != export[i][j])
				break ;
			j++;
			if (export[i][j] == '\0')
				return (i);
		}
		i++;
	}
	return (-1);
}
