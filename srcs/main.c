#include "../includes/pipex.h"

int main(int argc, char **argv)
{
	pid_t   pid;
	int     pipefd[2];
	FILE	*fd;
	int     read_return;
	char    buffer[11];

	if (pipe(pipefd) < 0)
		return (1);
	pid = fork();
	if (pid != 0)
	{
		printf("daddy\n");
		wait(NULL);
	}
	else
	{
		printf("son\n");
		fd = fopen("meuh.sh", "rb+");
		execve("./meuh.sh", NULL, NULL);
	}
}