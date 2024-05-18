/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:41:14 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 18:09:04 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_change_in(t_data *ms, t_process *process)
{
	int		i;
	int		fd;
	char	**redirects;

	i = 0;
	redirects = process->redirects;
	while (redirects[i])
	{
		if (ft_isoperator(redirects[i]) == LESS)
		{
			fd = open(redirects[i + 1], O_RDONLY);
			if (fd == -1)
				return (ft_nofile_err(ms, redirects[i + 1]));
			dup2(fd, 0);
			close(fd);
		}
		else if (ft_isoperator(redirects[i]) == LESS_LESS)
			dup2(process->heredoc_fd[0], 0);
		i += 2;
	}
}

void	output(t_data *ms, char *file)
{
	int		fd;

	fd = 0;
	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd == -1)
	{
		perror("minishell");
		if (!ft_ischild(ms))
			return ;
		else
			exit(errno);
	}
	dup2(fd, 1);
	close(fd);
}

void	ft_change_out(t_data *ms, t_process *process)
{
	int		i;
	int		fd;
	char	**redirects;

	i = 0;
	fd = 0;
	redirects = process->redirects;
	while (redirects[i])
	{
		if (ft_isoperator(redirects[i]) == GREAT)
			output(ms, redirects[i + 1]);
		else if (ft_isoperator(redirects[i]) == GREAT_GREAT)
		{
			fd = open(redirects[i + 1], O_CREAT | O_WRONLY | O_APPEND, 0777);
			if (fd == -1)
			{
				perror("minishell");
				if (ft_ischild(ms))
					exit(errno);
			}
			dup2(fd, 1);
			close(fd);
		}
		i += 2;
	}
}
