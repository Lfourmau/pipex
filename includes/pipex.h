#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_fd
{
    int fd_input;
    int fd_output;
} t_fd;

char	*create_command_path(char *cmd);
int     first_fork_child(int *pipefd, char *cmd, char *path);
int     first_fork_dad(int *pipefd, char *cmd, t_fd fd);

#endif