/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:42:25 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 17:42:25 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buff;
	unsigned char	buff_c;
	size_t			i;

	buff = (unsigned char *)s;
	buff_c = c;
	if (n != 0)
	{
		i = 0;
		while (i < n)
		{
			if (buff[i] == buff_c)
				return ((char *)&buff[i]);
			i++;
		}
	}
	return (NULL);
}
