/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:10:11 by ctasar            #+#    #+#             */
/*   Updated: 2024/05/18 17:40:01 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_export(t_data *ms, char *str)
{
	int		i;
	char	**export;
	char	**new_export;

	i = 0;
	export = ms->export;
	new_export = ft_calloc(sizeof(char **), ft_export_len(ms) + 2);
	while (export[i])
	{
		new_export[i] = ft_strdup(export[i]);
		i++;
	}
	new_export[i] = ft_strdup(str);
	ft_free_arr(ms->export);
	ms->export = new_export;
}

void	add_env(t_data *ms, char *str)
{
	int		i;
	char	**env;
	char	**new_env;

	i = 0;
	env = ms->env;
	new_env = ft_calloc(sizeof(char **), ft_env_len(ms) + 2);
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = ft_strdup(str);
	ft_free_arr(ms->env);
	ms->env = new_env;
}

void	export_check_chr(t_data *ms, int p_e, int p_ex, char *i)
{
	if (p_e == -1)
	{
		if (export_check_char(i))
			add_env(ms, i);
		else
		{
			export_err(ms, i);
			return ;
		}
	}
	if (p_ex == -1)
	{
		if (export_check_char(i))
			add_export(ms, i);
		else
		{
			export_err(ms, i);
			return ;
		}
	}
}

void	add_export_env(t_data *ms, char **input)
{
	int		pos_env;
	int		pos_export;

	if (check_env(ms, *input))
	{
		pos_env = is_include_env(ms, *input);
		pos_export = is_include_export(ms, *input);
		if (pos_env != -1)
			swap_env(ms, pos_env, *input);
		if (pos_export != -1)
			swap_export(ms, pos_export, *input);
		export_check_chr(ms, pos_env, pos_export, *input);
	}
}

void	ft_export(t_data *ms, char **input)
{
	input++;
	if (!*input)
		print_export(ms);
	while (*input)
	{
		add_export_env(ms, input);
		input++;
	}
	ft_set_path(ms);
	if (ft_ischild(ms))
		exit (EXIT_SUCCESS);
}
