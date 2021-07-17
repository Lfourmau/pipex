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

int	create_script()
{
	int fd;

	fd = open("meuh.sh", O_CREAT | O_RDWR, 0777);
	ft_putstr_fd("#! /bin/bash\n", fd);
	return (fd);
}

int main(int argc, char **argv)
{
	int fd_script;

	//if (parsing(argc, argv))
	//	return(error());
	fd_script = create_script();
	ft_putstr_fd("ls -la >> test2.txt\nrm meuh.sh", fd_script);
	execve("./meuh.sh", NULL, NULL);
	return (0);
}