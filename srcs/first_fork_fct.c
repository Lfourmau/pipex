#include "../includes/pipex.h"

int	first_fork_child(int *pipefd, char *cmd, char *path, t_fd *fd)
{
	close(pipefd[0]);
	close(1);
	pipefd[1] = dup(pipefd[1]);
	dup2(fd->fd_input, 0);
	execve(path, ft_split(cmd, ' '), NULL);
	return (0);
}

int	first_fork_dad(int *pipefd, char *cmd, t_fd *fd)
{
	int		pid_fork;
	char	*path;

	close(pipefd[1]);
	path = create_command_path(cmd);
	if (path == NULL)
		return (error());
	pid_fork = fork();
	if (pid_fork == 0)
	{
		close(1);
		dup2(fd->fd_output, 1);
		close(0);
		dup2(pipefd[0], 0);
		execve(path, ft_split(cmd, ' '), NULL);
	}
	else
	{
		wait(NULL);
		free(path);
	}
	return (0);
}
