#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    char line[256];
    int n = 0;
    scanf("%s", line);
    
    int pid;
    switch (pid = fork())
    {
    case 0:
        char *argv[] = {line, NULL};
        execvp(line, argv);
        return 0;
    
    default:
        waitpid(pid, NULL, 0);
        break;
    }
}