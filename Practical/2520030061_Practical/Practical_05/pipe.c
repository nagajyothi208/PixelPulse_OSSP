#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    int fd[2];
    pid_t pid;
    char message[] = "Hello from Producer";
    char buffer[100];

    pipe(fd);

    pid = fork();

    if (pid == 0)
    {
        // Child - Consumer
        close(fd[1]);

        read(fd[0], buffer, sizeof(buffer));

        printf("Consumer received: %s\n", buffer);

        close(fd[0]);
    }
    else
    {
        // Parent - Producer
        close(fd[0]);

        write(fd[1], message, strlen(message) + 1);

        printf("Producer sent: %s\n", message);

        close(fd[1]);
        wait(NULL);
    }

    return 0;
}
