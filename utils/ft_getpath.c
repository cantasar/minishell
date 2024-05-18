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

char	*ft_getpath(t_data *ms, char *cmd)
{
	char	*path;
	char	**paths;
	char	*new_cmd;

	check_dir(ms, cmd);
	if (!access(cmd, F_OK))
		return (ft_strdup(cmd));
	paths = ms->path;
	if (!paths)
		ft_not_found_err(ms, cmd);
	new_cmd = ft_strjoin("/", cmd);
	while (*paths)
	{
		path = ft_strjoin(*paths, new_cmd);
		if (!access(path, F_OK))
		{
			free(new_cmd);
			return (path);
		}
		free(path);
		paths++;
	}
	if (ft_strchr(cmd, '/'))
		ft_nofile_err(ms, cmd);
	free(new_cmd);
	return (NULL);
}
