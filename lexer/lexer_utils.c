#include "../minishell.h"

t_data g_ms;

t_lexer	*ft_new_list(char *str, t_tokens token)
{
	static int i;
	t_lexer *new;

	i = 0;
	new = (t_lexer *)malloc(sizeof(t_lexer));
	new->str = str;
	new->token = token;
	new->i = i;
	i++;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void    ft_list_addback(t_lexer **lst, t_lexer *new)
{
    if (*lst == NULL) {
        *lst = new;
        return;
    }
    t_lexer *tmp = *lst;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    new->prev = tmp;
}


void	ft_add_list(char *str, t_tokens token, t_lexer **list)
{
	printf("**ppp**\n");
	t_lexer *res;

	res = ft_new_list(str, token);
	if(!res)
		printf("hata");
	ft_list_addback(list, res);
}
