#include "../minishell.h"

// void	command_err(char *str)
// {
// 	errno = 127;
// 	write(2, "minishell: ", 11);
// 	write(2, str, ft_strlen(str));
// 	write(2, ": command not found\n", 20);
// 	if (is_child())
// 		exit(errno);
// }

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
	else if (type == 0)
		red = "newline";
	errno = 258;
	write(2, "minishell: syntax error near unexpected token '", 47);
	write(2, red, ft_strlen(red));
	write(2, "'\n", 2);
}

// void	directory_err(char *str)
// {
// 	errno = 126;
// 	write(2, "minishell: ", 11);
// 	write(2, str, ft_strlen(str));
// 	write(2, ": is a directory\n", 17);
// 	if (is_child())
// 		exit(errno);
// }

// void	no_file_err(char *str)
// {
// 	if (ft_strchr(str, '/'))
// 		errno = 127;
// 	else
// 		errno = 1;
// 	write(2, "minishell: ", 11);
// 	write(2, str, ft_strlen(str));
// 	write(2, ": No such file or directory\n", 28);
// 	if (is_child())
// 		exit(errno);
// }

// void	export_err(char *str)
// {
// 	printf(" \"%s\" : not a valid identifier\n", str);
// 	errno = 1;
// 	if (is_child())
// 		exit(errno);
// }
