#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

char **parse(char *line)
{
    char *word = strtok(line, " "); // ls -l -a
    char **words = malloc(sizeof(char *));
    int sz = 1;
    while (word && word[0] != '\n')
    {
        words[sz++ - 1] = strdup(word);
        word = strtok(NULL, " ");
        words = realloc(words, sizeof(char *) * sz);
    }
    
    if (words[sz - 2][strlen(words[sz - 2]) - 1] == '\n')
    {
        words[sz - 2][strlen(words[sz - 2]) - 1] = '\0';
    }
    words[sz] = NULL;
    return words;
}

int main()
{
    char *line = NULL;
    size_t n = 0;
    getline(&line, &n, stdin);
    char **argv = parse(line);

    int pid;
    switch (pid = fork())
    {
    case 0:
        execvp(argv[0], argv);
        return 0;

    default:
        waitpid(pid, NULL, 0);
        break;
    }
}