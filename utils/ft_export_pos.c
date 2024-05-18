/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:43:38 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 17:43:39 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	export_pos(char *str, char *export)
{
	int		pos;
	char	*tmp;

	pos = 0;
	while (export[pos] && export[pos] != '=')
		pos++;
	tmp = ft_substr(export, 0, pos);
	if (ft_strcmp(tmp, str))
	{
		free (tmp);
		return (TRUE);
	}
	free (tmp);
	return (FALSE);
}
