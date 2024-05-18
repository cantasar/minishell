/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:43:13 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 20:48:40 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*get_str(char *str, int	*pos, int type)
{
	int		first;
	char	*data;

	first = *pos;
	while (str[*pos] != type)
		(*pos)++;
	data = ft_substr(str, first, *pos - first);
	(*pos)++;
	return (data);
}

char	*parse_dollar_op(t_data *ms, char *str)
{
	int		i;
	int		first;
	char	*env;
	char	*result;
	char	*data;

	i = 0;
	result = "";
	data = get_str(str, &i, '$');
	result = ft_strjoin(result, data);
	first = i;
	if (str[i] == '?' && ++i)
		result = ft_strjoin(result, ft_itoa(errno));
	else
	{
		while (ft_isvalid(str[i]))
			(i)++;
		data = ft_substr(str, first, i - first);
		env = ft_getenv(ms, data);
		result = ft_strjoin(result, env);
		free(data);
	}
	data = get_str(str, &i, 0);
	result = ft_strjoin(result, data);
	return (result);
}

char	*ft_parse_dollar(t_data *ms, char *str)
{
	char	*tmp;
	char	*new_str;

	new_str = ft_strdup(str);
	while (ft_strchr(new_str, '$') && ft_in_squote(new_str))
	{
		tmp = new_str;
		new_str = parse_dollar_op(ms, new_str);
		free(tmp);
	}
	return (new_str);
}
