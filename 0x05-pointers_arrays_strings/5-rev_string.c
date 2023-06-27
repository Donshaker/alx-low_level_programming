#include "main.h"

/**
 * reverse_string - Reverses a string in-place.
 * @str: The string to be reversed.
 */
void reverse_string(char *str)
{
int length = 0;
int start = 0;
char temp;

while (str[length] != '\0')
length++;

 ength--;

while (start < length)
    {
temp = str[start];
str[start] = str[length];
str[length] = temp;
start++;
length--;
    }
}
