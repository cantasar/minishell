/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:45:12 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 18:39:13 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_c(int sig)
{
	(void)sig;
	*g_signal = TRUE;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	write(1, "\033[A", 3);
}

void	ctrl_d(char *input)
{
	if (!input)
	{
		printf("exit\n");
		exit(errno);
	}
}

void	ft_free_all(t_data *ms)
{
	ms->lexer_list = NULL;
	ms->process = NULL;
	ms->process_count = 0;
	ms->line = NULL;
}

void	ft_loop(t_data *ms, char **env)
{
	char	*line;

	ft_init_ms(ms, env);
	while (TRUE)
	{
		ft_check_flag(ms);
		ms->exit_signal = FALSE;
		signal(SIGINT, &ctrl_c);
		signal(SIGQUIT, SIG_IGN);
		line = readline("minishell$: ");
		ft_check_flag(ms);
		ctrl_d(line);
		line = ft_strtrim(line, " ", "\t");
		ms->line = ft_strdup(line);
		add_history(ms->line);
		if (ft_lexer(ms) && ft_parser(ms))
		{
			ft_execute(ms);
		}
		free(line);
		ft_free_all(ms);
		ft_free_lexer(ms);
		ft_free_process(ms);
	}
}

int	main(int argc, char *argv[], char **env)
{
	t_data	ms;

	if (argc != 1 || argv[1])
	{
		printf("Not accept arguments\n");
		exit(EXIT_SUCCESS);
	}
	ft_loop(&ms, env);
	return (0);
}
