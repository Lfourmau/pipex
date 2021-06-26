#include "../includes/pipex.h"

int main(int argc, char **argv)
{
    pid_t pid;

    printf("AVANT FORK\n");
    pid = fork();
    if (pid == 0)
        printf("APRES FORK PROCESS FILS\n");
    else
    {
        printf("APRES FORK PROCESS PAPS\n");
        wait(NULL);
    }
    printf("FIN FORK\n");
    
}