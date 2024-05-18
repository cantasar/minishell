/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istoken.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:45:00 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 17:45:01 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_istoken(int c)
{
	if (c == '|')
		return (2);
	else if (c == '<')
		return (3);
	else if (c == '>')
		return (5);
	else
		return (FALSE);
}
