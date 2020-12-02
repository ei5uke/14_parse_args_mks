#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *args[5], *token, *p;

char ** parse_args(char * line)
{
    p = line;
    int i = 0;
    while (p)
    {
        token = strsep(&p, " ");
        //printf("token: \t[%s]\n", token);
        args[i] = token;
        //printf("args[%d]: \t[%s]\n", i, args[i]);
        i++;
    }
    return args;
}

int main()
{
    char line[] = "ls -a -l";
    char **args = parse_args(line);
    //printf("args[0]: \t[%s]\n", args[0]);

    execvp("ls", args);//v stands for vector

    return 0;
}