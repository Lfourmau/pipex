#include "../includes/pipex.h"

int	error(void)
{
	printf("An error happened while execution of the prog\n");
	return (1);
}

int	parsing(int argc, char **argv, t_fd *fd)
{
	if (argc != 5)
		return (1);
	fd->fd_input = open(argv[1], O_RDONLY);
	if (fd->fd_input == -1)
		return (1);
	fd->fd_output = open(argv[4], O_WRONLY | O_TRUNC);
	if (fd->fd_output == -1)
	{
		close(fd->fd_input);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	pid;
	t_fd	fd;
	char	*path;
	int		pipefd[2];

	if (parsing(argc, argv, &fd))
		return (error());
	path = create_command_path(env, argv[2]);
	if (path == NULL)
		return (error());
	if (pipe(pipefd) == 1)
		return (error());
	pid = fork();
	if (pid == 0)
		first_fork_child(pipefd, argv[2], path, &fd);
	else if (pid > 0)
	{
		first_fork_dad(pipefd, argv[3], &fd, env);
		free(path);
		waitpid(pid, 0, 0);
	}
	else
		return (error());
	return (0);
}
