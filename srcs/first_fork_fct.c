#include "../includes/pipex.h"

int first_fork_child(int *pipefd, char *cmd, char *path)
{
	close(pipefd[0]);
	close(1);
	dup2(pipefd[1], 1);
	execve(path, ft_split(cmd, ' '), NULL);
	return (0);
}

int first_fork_dad(int *pipefd)
{
	close(pipefd[1]);
	return (0);
}