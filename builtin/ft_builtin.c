/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:06:52 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 17:59:31 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exec_builtin(t_data *ms, t_process *process)
{
	int	in;
	int	out;

	in = dup(0);
	out = dup(1);
	ft_change_in(ms, process);
	ft_change_out(ms, process);
	run_builtin(ms, process->execute);
	dup2(in, 0);
	dup2(out, 1);
	close(in);
	close(out);
}

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

void	run_builtin(t_data *ms, char **execute)
{
	int	type;

	type = ft_isbuiltin(execute[0]);
	if (type == CD)
		ft_cd(ms, execute);
	if (type == ENV)
		ft_env(ms);
	if (type == PWD)
		ft_pwd(ms);
	if (type == ECHO)
		ft_echo(ms, execute);
	if (type == EXIT)
		ft_exit(execute);
	if (type == UNSET)
		ft_unset(ms, execute);
	if (type == EXPORT)
		ft_export(ms, execute);
}
