#include "../minishell.h"

t_lexer	*ft_lexernew(char *str, int token)
{
	t_lexer		*new_element;
	static int	i = 0;

	new_element = (t_lexer *)malloc(sizeof(t_lexer));
	if (!new_element)
		return (0);
	new_element->str = str;
	new_element->token = token;
	new_element->i = i++;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}

void	ft_lexeradd_back(t_lexer *lst, t_lexer *new)
{
	t_lexer	*tmp;

	tmp = lst;
	if (lst == NULL)
	{
		lst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

int	add_node(char *str, t_tokens token, t_lexer *lexer_list)
{
	t_lexer	*node;

	node = ft_lexernew(str, token);
	if (!node)
		return (0);
	ft_lexeradd_back(lexer_list, node);
	return (1);
}


void read(t_lexer *list)
{
	add_node("abc", PIPE, list);
	add_node("def", PIPE, list);
	
}

int main(int argc, char const *argv[])
{
	t_lexer *list;

	read(list);

	printf("%s\n", list->str);
	list= list->next;
	printf("%s\n", list->str);

	// while (list->next != NULL)
	// {
	// 	list = list->next;
	// }
	
	return 0;
}