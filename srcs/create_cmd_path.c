#include "../includes/pipex.h"

char	*ret_path(char *path, char **words, int flag)
{
	if (flag == 0)
	{
		free_splits(words, number_of_split(words));
		return (path);
	}
	else
	{
		free_splits(words, number_of_split(words));
		free(path);
		return (NULL);
	}
}

static char	*create_cmd_util(char **cmd)
{
	char	*path;

	path = ft_strjoin("/usr/local/bin/", cmd[0]);
	if (open(path, O_RDONLY) != -1)
		return (ret_path(path, cmd, 0));
	free(path);
	path = ft_strjoin("/usr/bin/", cmd[0]);
	if (open(path, O_RDONLY) != -1)
		return (ret_path(path, cmd, 0));
	free(path);
	path = ft_strjoin("/bin/", cmd[0]);
	if (open(path, O_RDONLY) != -1)
		return (ret_path(path, cmd, 0));
	free(path);
	path = ft_strjoin("/usr/sbin/", cmd[0]);
	if (open(path, O_RDONLY) != -1)
		return (ret_path(path, cmd, 0));
	return (ret_path(path, cmd, 1));
}

char	*create_command_path(char *cmd)
{
	char	*path;
	char	**words;
	words = ft_split(cmd, ' ');
	path = ft_strjoin("/sbin/", words[0]);
	if (open(path, O_RDONLY) != -1)
		return (ret_path(path, words, 0));
	free(path);
	path = ft_strjoin("/usr/local/munki/", words[0]);
	if (open(path, O_RDONLY) != -1)
		return (ret_path(path, words, 0));
	free(path);
	path = ft_strjoin("/opt/X11/bin/", words[0]);
	if (open(path, O_RDONLY) != -1)
		return (ret_path(path, words, 0));
	else
	{
		free(path);
		return (create_cmd_util(words));
	}
}
