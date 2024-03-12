#include "../minishell.h"

void	print_tokens();

void	string_token(char *str)
{
	
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
			string_token(s);
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
