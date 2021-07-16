#include "../includes/pipex.h"

int main(int argc, char **argv)
{
	pid_t   pid;
	int     pipefd[2];
	int     read_return;
	char    buffer[11];

	if (pipe(pipefd) < 0)
		return (1);
	pid = fork();
	if (pid != 0)
	{
		close (pipefd[0]);
		printf("dad\n");
		write (pipefd[1], "Bonjour #1", 11);
		write (pipefd[1], "Bonjour #2", 11);
		write (pipefd[1], "Bonjour #3", 11);
		wait(NULL);
	}
	else
	{
		close(pipefd[1]);
		printf("child\n");
		while ((read_return = read(pipefd[0], buffer, 11)) > 0)
			printf("%s\n", buffer);
		if (read_return != 0)  
			return (1);
		printf("Finish le fish\n");
	}
}