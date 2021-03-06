#include "../includes/pipex.h"

void	first_fork_child(int *pipefd, char *cmd, char *path, t_fd *fd)
{
	close(pipefd[0]);
	dup2(pipefd[1], 1);
	dup2(fd->fd_input, 0);
	execve(path, ft_split(cmd, ' '), NULL);
	exit(1);
}

int	first_fork_dad(int *pipefd, char *cmd, t_fd *fd, char **env)
{
	int		pid_fork;
	char	*path;

	close(pipefd[1]);
	path = create_command_path(env, cmd);
	if (path == NULL)
		return (error());
	pid_fork = fork();
	if (pid_fork == 0)
	{
		dup2(fd->fd_output, 1);
		dup2(pipefd[0], 0);
		execve(path, ft_split(cmd, ' '), NULL);
		exit(1);
	}
	else if (pid_fork > 0)
	{
		free(path);
		waitpid(pid_fork, 0, 0);
	}
	else
		return (error());
	return (0);
}
