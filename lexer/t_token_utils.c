#include "../minishell.h"

t_token	*init_ttoken(char *str, enum e_ttype type)
{
	t_token *token;

	token = ft_calloc(sizeof(t_token), 1);
	token->str = str;
	token->type = type;
	token->next = NULL;
	token->prev = NULL;
	return (token);
}

void	token_add(t_token **token, t_token *new)
{
	t_token	*p_token;

	p_token = *token;
	if (!p_token)
		*token = new;
	else
	{
		while (p_token->next)
			p_token = p_token->next;
		p_token->next = new;
		new->prev = p_token;
	}
	return ;
}
