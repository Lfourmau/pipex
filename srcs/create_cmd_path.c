#include "../includes/pipex.h"

static int	find_path_index(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' &&
		env[i][2] == 'T' && env[i][3] == 'H')
			return (i);
		i++;
	}
	return (-1);
}

static char	**create_env_paths(char **env)
{
	char	**tmp;
	char	**paths;
	int		index;

	index = find_path_index(env);
	tmp = ft_split(env[index], '=');
	paths = ft_split(tmp[1], ':');
	free_splits(tmp, number_of_split(tmp));
	return (paths);
}

static char	*join_cmd_to_path(char *path, char *cmd)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(path, "/");
	res = ft_strjoin(tmp, cmd);
	free(tmp);
	return (res);
}

char	*create_command_path(char **env, char *cmd)
{
	char	**paths;
	char	**words;
	char	*cmd_path;
	int		i;

	paths = create_env_paths(env);
	words = ft_split(cmd, ' ');
	i = 0;
	while (paths[i])
	{
		cmd_path = join_cmd_to_path(paths[i], words[0]);
		if (open(cmd_path, O_RDONLY) != -1)
		{
			free_two_splits(words, paths);
			return (cmd_path);
		}
		else
			free(cmd_path);
		i++;
	}
	free_two_splits(words, paths);
	return (NULL);
}
