#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    struct DIR *dirp = opendir("./tmp/");
    if (dirp == NULL)
    {
        return 0;
    }

    struct dirent *dp = NULL;

    char *file_name[255];
    unsigned long inode_number[255];
    int sz = 0;

    while ((dp = readdir(dirp)) != NULL)
    {
        inode_number[sz] = dp->d_ino;
        file_name[sz] = dp->d_name;
        ++sz;
    }

    for (int i = 0; i < sz; i++)
    {
        for (int j = i + 1; j < sz; j++)
        {
            if (inode_number[j] != 0 && inode_number[j] == inode_number[i])
            {
                printf("%s - %s\n", file_name[i], file_name[j]);
            }
        }
    }

    (void)closedir(dirp);
    return 0;
}