#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char **s = (char**)malloc(sizeof(char*)); // fix
    char foo[] = "Hello World";
    *s = foo;
    printf("s is %p\n", s); // fix
    s[0] = foo;
    printf("s [0] is %s\n", s[0]);
    free(s);
    return (0);
}