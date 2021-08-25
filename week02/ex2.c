#include <stdio.h>
#include <string.h>

int main(){
    char *str = NULL;
    size_t len = 0;
    printf("Enter a line for reverse: ");
    getline(&str, &len, stdin);
    len = strlen(str) - 1;
    for(int i = 0; i < len / 2; ++i){
        char a = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = a;
    }
    printf("Reverse line: ");
    printf("%s", str);
    return 0;
}