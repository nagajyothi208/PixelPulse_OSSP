#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    pid_t p1, p2;

    pipe(fd);

    p1 = fork();

    if (p1 == 0)
    {
        // First child: ls -l
        close(fd[0]);

        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);

        execlp("ls", "ls", "-l", NULL);

        printf("Error executing ls\n");
    }

    p2 = fork();

    if (p2 == 0)
    {
        // Second child: grep ".c"
        close(fd[1]);

        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);

        execlp("grep", "grep", ".c", NULL);

        printf("Error executing grep\n");
    }

    // Parent
    close(fd[0]);
    close(fd[1]);

    waitpid(p1, NULL, 0);
    waitpid(p2, NULL, 0);

    return 0;
}
