#include "../includes/pipex.h"

int	error()
{
	printf("An error happened while execution of the prog\n");
	return (1);
}

int parsing(int argc, char **argv)
{
	int fd;

	if (argc != 5)
		return (1);
	fd = open(argv[1], 'r');
	if (fd == -1)
		return (1);
	fd = open(argv[4], 'r');
	if (fd == -1)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	execve("/bin/ls", ft_split(argv[1], ' '), NULL);
	return (0);
}