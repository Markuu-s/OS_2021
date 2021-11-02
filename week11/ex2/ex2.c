#include <stdio.h>
#include <dirent.h>
int main()
{
    struct dirent *arr_file;
    DIR *directory = opendir(".");

    if (!directory)
    {
        return -1;
    }

    while ((arr_file = readdir(directory)) != NULL)
    {
        if (arr_file->d_name[0] != '.')
        {
            printf("%s ", arr_file->d_name);
        }
    }

    closedir(directory);
    return 0;
}