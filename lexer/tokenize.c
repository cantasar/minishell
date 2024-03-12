#include "../minishell.h"

void	print_tokens();

void	skip_spaces(char **s)
{
	while (**s && is_space(**s))
		s++;
}

void find_end_pos(char **str, char type) {
	(*str)++;

	while (**str)
	{
		if (**str == type)
		{
			(*str)++;
			if (!is_space(**str) || !is_operator(*str))
				return;
			else
				while (**str && !is_space(**str) && !is_operator(*str))
					(*str)++;
		}
		(*str)++;
	}
}


void without_quote_parse(char **str) {
	while (**str) {
		if (is_space(**str) || is_operator(*str))
			break;
		(*str)++;
	}
}


void	string_token(char **str)
{
	int		len;
	char	*head;
	char	*token_str;

	skip_spaces(str);
	head = *str;
	if (**str == '"' || **str == '\'') {
		char quote_type = **str;
		(*str)++;
		find_end_pos(str, quote_type);
	} else {
		without_quote_parse(str);
	}
	len = *str - head;
	if (len > 0) {
		token_str = ft_substr(head, 0, len);
		token_add(&g_mini.tokens, init_ttoken(token_str, STRING));
	}
}

void	tokenize(char *s)
{
	while (*s)
	{
		if (s[0] == '>' && s[1] == '>')
		{
			token_add(&g_mini.tokens, init_ttoken(">>", RED_APPEND));
			s = s + 2;
		}
		else if (s[0] == '<' && s[1] == '<')
		{
			token_add(&g_mini.tokens, init_ttoken("<<", HERE_DOC));
			s = s + 2;
		}
		else if (s[0] == '|')
		{
			token_add(&g_mini.tokens, init_ttoken("|", PIPE));
			s++;
		}
		else if (s[0] == '<')
		{
			token_add(&g_mini.tokens, init_ttoken("<", RED_INPUT));
			s++;
		}
		else if (s[0] == '>')
		{
			token_add(&g_mini.tokens, init_ttoken(">", RED_OUTPUT));
			s++;
		}
		else
		{
			string_token(&s);
			s++;
		}
	}
	print_tokens();
}

void	print_tokens()
{
	t_token *p = g_mini.tokens;
	printf("\n------Tokenize-------\n");
	int i = 0;
	while (p)
	{

		printf("%d\n", i);
		printf("%s\n", p->str);
		printf("%u\n", p->type);
		printf("----\n");
		p = p->next;
		i++;
	}
	
}
