/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:45:06 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 18:37:14 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_export(t_data *ms, char **env)
{
	size_t	i;
	size_t	len;
	char	**head;

	head = env;
	while (*head)
		head++;
	len = head - env;
	ms->export = ft_calloc(sizeof(char **), len + 1);
	i = -1;
	while (++i < len)
		ms->export[i] = ft_strdup(env[i]);
}
