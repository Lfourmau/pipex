#include "../includes/pipex.h"

int	error()
{
	printf("An error happened while execution of the prog\n");
	return (1);
}

int parsing(int argc, char **argv, t_fd fd)
{
	if (argc != 5)
		return (1);
	fd.fd_input = open(argv[1], 'r');
	if (fd.fd_input == -1)
		return (1);
	fd.fd_output = open(argv[4], 'r');
	if (fd.fd_output == -1)
		return (1);
	return (0);
}

char	*create_command(char *cmd)
{
	char *command;
	char **words;

	words = ft_split(cmd, ' ');
	command = ft_strjoin("/bin/", words[0]);
	return (command);
}
int main(int argc, char **argv)
{
	t_fd fd;
	char *command;
	int fd_test = open("text.txt", O_RDWR);
	int	pid;
	int pipefd[2];
	//if (parsing(argc, argv, fd))
	//	return (error());
	close(1);
	dup2(fd_test, 1);
	command = create_command(argv[1]);
	execve(command, ft_split(argv[1], ' '), NULL);
	return (0);
}