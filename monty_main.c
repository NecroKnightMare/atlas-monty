#include "monty.h"
/**
 * 
 * 
 * 
 */
int main (int argc, char*argv[])
{
    int line_num = 0;
    size_t length = 0;
    ssize_t read;
    FILE *file;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename, argv[1]);
        exit(EXIT_FAILURE);
    }

    fclose(file);
    return (0);
}