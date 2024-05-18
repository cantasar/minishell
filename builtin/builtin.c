/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:06:52 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 17:16:54 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
