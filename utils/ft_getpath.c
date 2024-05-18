/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_getpath.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ctasar <ctasar@student.42istanbul.com.t	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/05/18 17:43:40 by ctasar			#+#	#+#			 */
/*   Updated: 2024/05/18 18:27:54 by ctasar		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../minishell.h"

void	directory_err(t_data *ms, char *str)
{
	(void)ms;
	errno = 126;
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, ": is a directory\n", 17);
	if (ft_ischild(ms))
		exit(errno);
}

void	check_dir(t_data *ms, char *cmd)
{
	DIR	*dir;

	if (!cmd)
		exit(EXIT_SUCCESS);
	dir = opendir(cmd);
	if (dir && readdir(dir))
	{
		closedir(dir);
		directory_err(ms, cmd);
	}
}

int	ft_prepare_path_search(t_data *ms, char *cmd, char **new_cmd)
{
	check_dir(ms, cmd);
	if (!access(cmd, F_OK))
		return (1);
	if (!ms->path)
	{
		ft_not_found_err(ms, cmd);
		return (-1);
	}
	*new_cmd = ft_strjoin("/", cmd);
	return (0);
}

char	*ft_getpath(t_data *ms, char *cmd)
{
	char	*path;
	char	*new_cmd;
	int		result;

	result = ft_prepare_path_search(ms, cmd, &new_cmd);
	if (result == 1)
		return (ft_strdup(cmd));
	else if (result == -1)
		return (NULL);
	while (*ms->path)
	{
		path = ft_strjoin(*ms->path++, new_cmd);
		if (!access(path, F_OK))
		{
			free(new_cmd);
			return (path);
		}
		free(path);
	}
	free(new_cmd);
	if (ft_strchr(cmd, '/'))
		ft_nofile_err(ms, cmd);
	return (NULL);
}
