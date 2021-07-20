#include "../includes/pipex.h"

int	error()
{
	printf("An error happened while execution of the prog\n");
	return (1);
}

int parsing(int argc, char **argv, t_fd *fd)
{
	if (argc != 5)
		return (1);
	fd->fd_input = open(argv[1], O_RDWR);
	if (fd->fd_input == -1)
		return (1);
	fd->fd_output = open(argv[4], O_RDWR);
	if (fd->fd_output == -1)
		return (1);
	return (0);
}

void build_first_cmd(char **argv)
{
	argv[2] = ft_strjoin(argv[2], " ");
	argv[2] = ft_strjoin(argv[2], argv[1]);
}

int main(int argc, char **argv)
{
	pid_t 	pid;
	t_fd	fd;
	char	*path;
	int		pipefd[2];

	if (parsing(argc, argv, &fd))
		return (error());
	path = create_command_path(argv[2]);
	build_first_cmd(argv);
	if (path == NULL)
		return (error());
	pipe(pipefd);
	pid = fork();
	if (pid == 0)
		first_fork_child(pipefd, argv[2], path);
	else
	{
		wait(NULL);
		first_fork_dad(pipefd, argv[3], &fd);
	}
	return (0);
}