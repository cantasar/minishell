// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   export.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ctasar <ctasar@student.42istanbul.com.t    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/05/18 00:10:11 by ctasar            #+#    #+#             */
// /*   Updated: 2024/05/18 13:49:24 by ctasar           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../minishell.h"

// void	add_export(t_data *ms, char *str)
// {
// 	int		i;
// 	char	**export;
// 	char	**new_export;

// 	i = 0;
// 	export = ms->export;
// 	new_export = ft_calloc(sizeof(char **), export_len() + 2);
// 	while (export[i])
// 	{
// 		new_export[i] = ft_strdup(export[i]);
// 		i++;
// 	}
// 	new_export[i] = ft_strdup(str);
// 	free_array(ms->export);
// 	ms->export = new_export;
// }

// void	add_env(t_data *ms, char *str)
// {
// 	int		i;
// 	char	**env;
// 	char	**new_env;

// 	i = 0;
// 	env = ms->env;
// 	new_env = ft_calloc(sizeof(char **), env_len() + 2);
// 	while (env[i])
// 	{
// 		new_env[i] = ft_strdup(env[i]);
// 		i++;
// 	}
// 	new_env[i] = ft_strdup(str);
// 	free_array(ms->env);
// 	ms->env = new_env;
// }

// void	export_env_check_char(t_data *ms, int pos_env, int pos_export, char *input)
// {
// 	if (pos_env == -1)
// 	{
// 		if (export_check_char(input))
// 			add_env(ms, input);
// 		else
// 		{
// 			export_err(input);
// 			return ;
// 		}
// 	}
// 	if (pos_export == -1)
// 	{
// 		if (export_check_char(input))
// 			add_export(ms, input);
// 		else
// 		{
// 			export_err(input);
// 			return ;
// 		}
// 	}
// }

// void	add_export_env(t_data *ms, char **input)
// {
// 	int		pos_env;
// 	int		pos_export;

// 	if (check_env(*input))
// 	{
// 		pos_env = is_include_env(*input);
// 		pos_export = is_include_export(*input);
// 		if (pos_env != -1)
// 			swap_env(pos_env, *input);
// 		if (pos_export != -1)
// 			swap_export(pos_export, *input);
// 		export_env_check_char(ms, pos_env, pos_export, *input);
// 	}
// }

// void	ft_export(t_data *ms, char **input)
// {
// 	input++;
// 	if (!*input)
// 		print_export();
// 	while (*input)
// 	{
// 		add_export_env(ms, input);
// 		input++;
// 	}
// 	ft_set_path(ms);
// 	if (ft_ischild(ms))
// 		exit (EXIT_SUCCESS);
// }
