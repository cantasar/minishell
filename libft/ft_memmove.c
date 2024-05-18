/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:42:29 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 17:42:29 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_p;
	char	*src_p;

	dst_p = (char *)dst;
	src_p = (char *)src;
	if (dst == src)
		return (dst);
	if (src_p < dst_p)
	{
		while (len--)
			dst_p[len] = src_p[len];
		return (dst);
	}
	while (len--)
		*dst_p++ = *src_p++;
	return (dst);
}
