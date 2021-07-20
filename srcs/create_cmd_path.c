#include "../includes/pipex.h"

static char *create_cmd_util(char **cmd)
{
    char *path;

    path = ft_strjoin("/usr/local/bin/", cmd[0]);
	if (fopen(path ,"r"))
		return (path);
	path = ft_strjoin("/usr/bin/", cmd[0]);
	if (fopen(path ,"r"))
		return (path);
	path = ft_strjoin("/bin/", cmd[0]);
	if (fopen(path ,"r"))
		return (path);
	path = ft_strjoin("/usr/sbin/", cmd[0]);
	if (fopen(path ,"r"))
		return (path);
    return (NULL);
}
//to free in case of error from open : give the **words to create_cmd_utils in create_command_path and free it by a free_chains before the return (NULL);
char	*create_command_path(char *cmd)
{
	char *path;
	char **words;

	words = ft_split(cmd, ' ');
	path = ft_strjoin("/sbin/", words[0]);
	if (fopen(path ,"r"))
		return (path);
	path = ft_strjoin("/usr/local/munki/", words[0]);
	if (fopen(path ,"r"))
		return (path);
	path = ft_strjoin("/opt/X11/bin/", words[0]);
	if (fopen(path ,"r"))
		return (path);
    else
        return (create_cmd_util(words));
}