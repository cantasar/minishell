/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:43:27 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 18:37:53 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_add_arr(char **arr, char *new)
{
	int		i;
	int		len;
	char	**new_arr;

	i = 0;
	len = 0;
	while (arr && arr[len])
		len++;
	new_arr = ft_calloc(sizeof(char *), len + 2);
	while (i < len)
	{
		new_arr[i] = arr[i];
		i++;
	}
	new_arr[i] = new;
	if (arr[0])
		free(arr);
	return (new_arr);
}
