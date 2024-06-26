/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_squote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:43:41 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 18:36:34 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_in_squote(char *str)
{
	int		i;
	int		single_quote;
	int		double_quote;

	i = 0;
	single_quote = TRUE;
	double_quote = FALSE;
	while (str[i] && str[i] != '$')
	{
		if (str[i] == S_Q)
			single_quote = double_quote;
		if (str[i] == D_Q)
			double_quote = !double_quote;
		i++;
	}
	if (!ft_isvalid(*(ft_strchr(str, '$') + 1)))
		return (FALSE);
	return (single_quote);
}
