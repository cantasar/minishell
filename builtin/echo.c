/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:07:29 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 00:08:16 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	put_char(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		write(STDOUT_FILENO, &(input[i]), 1);
		i++;
	}
}

int	skip_flag(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (str[i])
	{
		if (str[i][0] == '-' && str[i][1] == 'n')
		{
			while (str[1][j])
			{
				if (str[1][j] == 'n')
					j++;
				else
					return (1);
			}
		}
		else
			break ;
		i++;
	}
	return (i);
}

void	builtin_echo(t_data *ms, char **input)
{
	int	i;
	int	flag;

	i = 1;
	flag = TRUE;
	i = skip_flag(input);
	if (i > 1)
		flag = FALSE;
	while (input[i])
	{
		put_char(input[i]);
		if (input[i + 1])
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
	if (flag)
		write(STDOUT_FILENO, "\n", 1);
	if (ft_ischild(ms))
		exit(EXIT_SUCCESS);
}
