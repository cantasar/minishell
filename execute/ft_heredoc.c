/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:41:24 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 18:10:10 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_close_hd(int sig)
{
	(void)sig;
	*g_signal = TRUE;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
}

void	ft_get_hd_input(t_data *ms, int *fd, char *endline)
{
	char		*input;

	if (pipe(fd) < 0)
		return (perror("minishell"));
	while (1)
	{
		signal(SIGINT, &ft_close_hd);
		input = readline("> ");
		if (!input || ft_strcmp(input, endline) || ms->exit_signal)
		{
			free(input);
			break ;
		}
		write(fd[1], input, ft_strlen(input));
		write(fd[1], "\n", 1);
		free(input);
	}
	close(fd[1]);
}

void	ft_heredoc(t_data *ms)
{
	t_process	*process;
	char		**redirects;
	int			i;

	process = ms->process;
	while (process)
	{
		redirects = process->redirects;
		i = 0;
		while (redirects[i] && !(ms->exit_signal))
		{
			if (redirects[i][0] == '<' && redirects[i][1] == '<')
				ft_get_hd_input(ms, ms->process->heredoc_fd, redirects[i + 1]);
			i += 2;
		}
		process = process->next;
	}
}
