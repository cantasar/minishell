/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:42:14 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 17:42:14 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*tmp;

	ptr = *lst;
	while (ptr)
	{
		tmp = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = tmp;
	}
	*lst = NULL;
	free(ptr);
}
