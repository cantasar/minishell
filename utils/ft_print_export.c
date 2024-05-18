/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:45:04 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 17:45:05 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_export(t_data *ms)
{
	char	**export;

	export = ms->export;
	while (*export)
	{
		printf("declare -x %s\n", *export);
		export++;
	}
	if (ft_ischild(ms))
		exit (EXIT_SUCCESS);
}
