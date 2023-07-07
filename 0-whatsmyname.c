#include "main.h"

int main(int argc, char *argv[])
{
    (void)argc; /* Unused parameter */

    print_program_name(argv);

    return 0;
}

void print_program_name(char *argv[])
{
    int i = 0;

    while (argv[0][i] != '\0')
    {
        _putchar(argv[0][i]);
        i++;
    }
    _putchar('\n');
}

int _putchar(char c)
{
    return putchar(c);
}

