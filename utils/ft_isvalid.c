/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:45:02 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 18:36:49 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_isvalid(char c)
{
	return ((c >= 'a' && c <= 'z') || \
			(c >= 'A' && c <= 'Z') || \
			(c >= '0' && c <= '9') || \
			(c == '_') || (c == '?'));
}
