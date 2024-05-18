/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:41:36 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 18:10:21 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lexer	*ft_new_token(char *str, t_tokens token)
{
	t_lexer	*new;

	new = ft_calloc(sizeof(t_lexer), 1);
	new->str = str;
	new->token = token;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_token_addback(t_lexer **token, t_lexer *last)
{
	t_lexer	*i_token;

	i_token = *token;
	if (!i_token)
		*token = last;
	else
	{
		while (i_token->next)
			i_token = i_token->next;
		i_token->next = last;
		last->prev = i_token;
	}
}

int	ft_token(char *str, t_tokens token, t_lexer **list)
{
	t_lexer	*new;

	new = ft_new_token(str, token);
	if (!new)
		return (0);
	ft_token_addback(list, new);
	return (1);
}
