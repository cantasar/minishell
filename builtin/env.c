/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:08:35 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 00:09:11 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_env(t_data *ms)
{
	char	**env;

	env = ms->env;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	if (ft_ischild(ms))
		exit (EXIT_SUCCESS);
}
