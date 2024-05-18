/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:41:41 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 18:11:05 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_empty_line(t_data *ms)
{
	if (!ms->line)
		return (TRUE);
	if (ms->line[0] == '\0')
		return (TRUE);
	return (FALSE);
}

int	ft_check_pipes(t_data *ms)
{
	int	len;

	len = ft_strlen(ms->line) - 1;
	if (ms->line[0] == '|')
	{
		ft_token_err(PIPE);
		return (TRUE);
	}
	else if (ms->line[len] == '|')
	{
		ft_token_err(PIPE);
		return (TRUE);
	}
	return (FALSE);
}

int	ft_find_matching_quote(char *line, int i, int *num_del, int del)
{
	int	j;

	j = i + 1;
	*num_del += 1;
	while (line[j] && line[j] != del)
		j++;
	if (line[j] == del)
		*num_del += 1;
	return (j - i);
}

int	ft_check_quotes(char *line)
{
	int	i;
	int	s_q;
	int	d_q;

	s_q = 0;
	d_q = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == 34)
			i += ft_find_matching_quote(line, i, &d_q, D_Q);
		if (line[i] == 39)
			i += ft_find_matching_quote(line, i, &s_q, S_Q);
		if ((int)ft_strlen(line) == i)
			break ;
	}
	if ((d_q > 0 && d_q % 2 != 0) || (s_q > 0 && s_q % 2 != 0))
	{
		ft_putstr_fd("syntax error: unable to locate closing quotation\n", 2);
		return (TRUE);
	}
	return (FALSE);
}

int	ft_check_operator(char *str)
{
	int	i;

	i = 0;
	while (str[++i])
	{
		if (ft_istoken(str[i - 1]) && ft_iswhitespace(str[i]))
		{
			while (ft_iswhitespace(str[i]))
				i++;
			if (ft_istoken(str[i]))
			{
				if (str[i] == '<' && str[i + 1] == '<')
					return (FALSE);
				else
					return (TRUE);
			}
		}
	}
	if (ft_istoken(str[ft_strlen(str) - 1]))
		return (TRUE);
	return (FALSE);
}
