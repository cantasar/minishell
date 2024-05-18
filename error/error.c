#include "../minishell.h"

void	ft_not_found_err(t_data *ms, char *str)
{
	(void)ms;
	errno = 127;
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, ": command not found\n", 20);
	exit(errno);
}

void	ft_token_err(int type)
{
	char	*red;

	if (type == LESS_LESS)
		red = "<<";
	else if (type == LESS)
		red = "<";
	else if (type == GREAT)
		red = ">";
	else if (type == GREAT_GREAT)
		red = ">>";
	else if (type == PIPE)
		red = "|";
	else
		red = "newline";
	errno = 258;
	write(2, "minishell: syntax error near unexpected token '", 47);
	write(2, red, ft_strlen(red));
	write(2, "'\n", 2);
}

void	ft_nofile_err(t_data *ms, char *str)
{
	(void)ms;
	if (ft_strchr(str, '/'))
		errno = 127;
	else
		errno = 1;
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, ": No such file or directory\n", 28);
	exit(errno);
}

void	export_err(t_data *ms, char *str)
{
	printf(" \"%s\" : not a valid identifier\n", str);
	errno = 1;
	if (ft_ischild(ms))
		exit(errno);
}
