/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:42:58 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 17:42:58 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	s2_len;

	i = 0;
	s2_len = ft_strlen(s2);
	if (s2_len == 0 || s1 == s2)
		return ((char *)s1);
	if (len != 0)
	{
		while (s1[i] && i <= len - s2_len)
		{
			j = 0;
			while (s2[j] && s2[j] == s1[i + j])
				j++;
			if (j == s2_len)
				return ((char *)&s1[i]);
			i++;
		}
	}
	return (NULL);
}
