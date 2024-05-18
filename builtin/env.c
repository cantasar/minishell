/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:08:35 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 13:47:46 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(t_data *ms)
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
