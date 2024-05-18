/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:43:32 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 17:43:33 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_env_len(t_data *ms)
{
	char	**env;

	env = ms->env;
	while (*env)
		env++;
	return (env - ms->env);
}

int	ft_export_len(t_data *ms)
{
	char	**export;

	export = ms->export;
	while (*export)
		export++;
	return (export - ms->export);
}
