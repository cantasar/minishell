#include "../minishell.h"

int	ft_isbuiltin(char *command)
{
	if (ft_strcmp(command, "cd"))
		return (CD);
	if (ft_strcmp(command, "env"))
		return (ENV);
	if (ft_strcmp(command, "pwd"))
		return (PWD);
	if (ft_strcmp(command, "echo"))
		return (ECHO);
	if (ft_strcmp(command, "exit"))
		return (EXIT);
	if (ft_strcmp(command, "unset"))
		return (UNSET);
	if (ft_strcmp(command, "export"))
		return (EXPORT);
	return (FALSE);
}

	void	builtin_pwd(void)
	{
		char	*result;

		result = getcwd((void *)0, 0);
		if (!result)
			perror("minishell ");
		else
			printf("%s\n", result);
		free(result);
		// if (is_child())
		// 	exit(errno);
	}


void	run_builtin(char **execute)
{
	int	type;

	type = ft_isbuiltin(execute[0]);
	// if (type == CD)
	// 	builtin_cd(execute);
	// if (type == ENV)
	// 	builtin_env();
	if (type == PWD)
		builtin_pwd();
	// if (type == ECHO)
	// 	builtin_echo(execute);
	// if (type == EXIT)
	// 	builtin_exit(execute);
	// if (type == UNSET)
	// 	builtin_unset(execute);
	// if (type == EXPORT)
	// 	builtin_export(execute);
}
