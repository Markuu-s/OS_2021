#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>

static const char *const evval[3] = {
    "RELEASED",
    "PRESSED ",
};

typedef struct
{
    int sz;
    char *ch;
} vector;

void init_vector(vector *v)
{
    v->sz = 0;
    v->ch = malloc(1024 * sizeof(char));
}

void add(vector *v, char adding)
{
    v->ch[v->sz++] = adding;
}

void clear(vector *v)
{
    v->sz = 0;
}

static const char *const typePressed[3] = {
    "PE",
    "CAP",
    "NONE",
};

static const char *const messengeByType[2] = {
    "I passed the Exam!\n",
    "Get some cappuccino!\n",
};

int whatTypePressed(vector *v)
{
    if (v->sz < 2 || v->sz > 3)
    {
        return 2;
    }
    if (v->sz == 2 && v->ch[0] == 'P' && v->ch[1] == 'E')
    {
        return 0;
    }
    if (v->sz == 3 && v->ch[0] == 'C' && v->ch[1] == 'A' && v->ch[2] == 'P')
    {
        return 1;
    }
}

int checkToAdd(vector* v, char x)
{
    if(v->sz > 0)
    {
        if (x == v->ch[v->sz - 1])
        {
            return 0;
        }
        return 1;
    }
    else
    {
        return 1;
    }
}

int main(void)
{
    const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event ev;
    ssize_t n;
    int fd;

    fd = open(dev, O_RDONLY);
    if (fd == -1)
    {
        fprintf(stderr, "Cannot open %s: %s.\n", dev, strerror(errno));
        return EXIT_FAILURE;
    }

    vector *v;
    init_vector(v);
    while (1)
    {
        n = read(fd, &ev, sizeof(ev));

        if (n == (ssize_t)-1)
        {
            if (errno == EINTR)
                continue;
            else
                break;
        }
        else if (n != sizeof ev)
        {
            errno = EIO;
            break;
        }

        if (ev.type == EV_KEY)
        {
            if (ev.value == 0)
            {
                if ((int)ev.code == 25)
                {
                    char x = 'P';
                    if (checkToAdd(v, x))
                        add(v, x);
                }
                else if ((int)ev.code == 18)
                {
                    char x = 'E';
                    if (checkToAdd(v, x))
                        add(v, x);
                }
                else if ((int)ev.code == 46)
                {
                    char x = 'C';
                    if (checkToAdd(v, x))
                        add(v, x);
                }
                else if ((int)ev.code == 30)
                {
                    char x = 'A';
                    if (checkToAdd(v, x))
                        add(v, x);
                }
                else
                {
                    clear(v);
                }
            }
            else
            {
                clear(v);
            }
        }

        for (int i = 0; i < 2; ++i)
        {
            if (whatTypePressed(v) == i)
            {
                printf("%s\n", messengeByType[i]);
                clear(v);
            }
        }
    }

    fflush(stdout);
    fprintf(stderr, "%s.\n", strerror(errno));
    return EXIT_FAILURE;
}