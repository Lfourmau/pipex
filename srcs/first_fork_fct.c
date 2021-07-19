#include "../includes/pipex.h"

int first_fork_child(int *pipefd, char *cmd, char *path)
{
	close(pipefd[0]);
	close(1);
	dup2(pipefd[1], 1);
	execve(path, ft_split(cmd, ' '), NULL);
	return (0);
}

int first_fork_dad(int *pipefd, char *cmd, t_fd fd)
{
	int pid_fork;
	char *path;

	close(pipefd[1]);
	path = create_command_path(cmd);
	dup2(pipefd[1], fd.fd_output);
	pid_fork = fork();
	if (pid_fork == 0)
	{
		close(pipefd[0]);
		execve(path, ft_split(cmd, ' '), NULL);
	}
	else
		wait(NULL);
	return (0);
}