/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:06:49 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 13:50:05 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(t_data *ms)
{
	char	*result;

	result = getcwd((void *)0, 0);
	if (!result)
		perror("minishell ");
	else
		printf("%s\n", result);
	free(result);
	if (ft_ischild(ms))
		exit(errno);
}
