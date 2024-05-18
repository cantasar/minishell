/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isoperator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:44:56 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 17:44:57 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_isoperator(char *str)
{
	if (!str)
		return (0);
	if (str[0] == '<' && str[1] == '<')
		return (LESS_LESS);
	if (str[0] == '>' && str[1] == '>')
		return (GREAT_GREAT);
	if (str[0] == '<')
		return (LESS);
	if (str[0] == '>')
		return (GREAT);
	if (str[0] == '|')
		return (PIPE);
	return (0);
}
