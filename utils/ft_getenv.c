/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:43:39 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 17:43:40 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_split_env(char *str)
{
	while (*str != '=')
		str++;
	str++;
	return (ft_strdup(str));
}

char	*ft_getenv(t_data *ms, char *str)
{
	size_t	len;
	char	**env;
	char	*new_str;

	env = ms->env;
	new_str = ft_strjoin(str, "=");
	len = ft_strlen(new_str);
	while (*env)
	{
		if (!ft_strncmp(*env, new_str, len))
		{
			free(new_str);
			return (ft_split_env(*env));
		}
		env++;
	}
	free(new_str);
	return (ft_calloc(sizeof(char *), 1));
}
