/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:45:09 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 17:45:10 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	swap_export(t_data *ms, int pos, char *input)
{
	char	*temp;

	temp = ms->export[pos];
	ms->export[pos] = ft_strdup(input);
	free(temp);
}

void	swap_env(t_data *ms, int pos, char *input)
{
	char	*temp;

	temp = ms->env[pos];
	ms->env[pos] = ft_strdup(input);
	free(temp);
}
