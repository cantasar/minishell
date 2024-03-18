#include "../minishell.h"

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

void	ft_list_addback(t_lexer **list, t_lexer *last)
{
	t_lexer *head;

	head = *list;
	if (list == NULL)
	{
		*list = last;
		return ;
	}
	while (head->next)
		head = head->next;
	head->next = last;
	last->prev = head;
}

void	ft_add_list(char *str, t_tokens token, t_lexer **list)
{
	t_lexer *res;

	res = ft_new_list(str, token);
	ft_list_addback(&g_ms.lexer_list, res);

}

int main(int argc, char const *argv[])
{
	t_lexer *a1 = ft_new_list("abc", PIPE);
	t_lexer *a2 = ft_new_list("abcdef", GREAT);
	a1->next = a2;
	a2->prev = a1;

	t_lexer *head = a1;
	while (head->next)
	{
		printf("\n*******\nstr= %s\ntoken= %d\n********\n", head->str, head->token);
		head = head->next;
	}
	

	return 0;
}