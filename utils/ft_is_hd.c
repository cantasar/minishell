/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_hd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:43:42 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 17:43:43 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_hd(t_process *process)
{
	int	i;

	i = 0;
	while (process->redirects[i])
	{
		if (ft_isoperator(process->redirects[i]) == LESS_LESS)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
