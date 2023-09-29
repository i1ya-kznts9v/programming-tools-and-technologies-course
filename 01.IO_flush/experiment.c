#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

typedef struct options
{ 
    bool redirect; 
    bool newline; 
    bool flush; 
} args;

args parse_args(int argc, char *argv[]) 
{
    args args = 
    {
        false,
        false, 
        false
    };

    int opt;
    while (-1 != (opt = getopt(argc, argv, "rnf")))
    {
        switch (opt)
        {
            case 'r':
                args.redirect = true;
                break;
            case 'n':
                args.newline = true;
                break;
            case 'f':
                args.flush = true;
                break;
            default:
                exit(1);
        }
    }
    
    return args;
}

int main(int argc, char *argv[])
{
    args args = parse_args(argc, argv);

    if (args.redirect)
    {
        freopen("result.txt", "w", stdout);
        freopen("result.txt", "w", stderr);
    }

    char *msg = malloc(32);
    if (args.newline)
        strcpy(msg, "Output stream!\n");
    else 
        strcpy(msg, "Output stream!");
    fputs(msg, stdout);
    
    if (args.flush)
        fflush(stdout);

    if (args.newline)
        strcpy(msg, "Error output stream!\n");
    else 
        strcpy(msg, "Error output stream!");
    fputs(msg, stderr);

    if (args.flush)
        fflush(stderr);

    free(msg);
    return 0;
}
