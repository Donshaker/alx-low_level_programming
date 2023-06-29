#include "main.h"

/**
 * rot13 - Encodes a string using ROT13
 * @str: The string to encode
 *
 * Return: Pointer to the encoded string 'str'
 */
char *rot13(char *str)
{
    int i, j;
    char alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    /* Loop through each character of the string */
    for (i = 0; str[i] != '\0'; i++)
    {
        /* Loop through the alphabets array */
        for (j = 0; alphabets[j] != '\0'; j++)
        {
            /* Check if the current character is an alphabet */
            if (str[i] == alphabets[j])
            {
                /* Replace the character with the corresponding ROT13 character */
                str[i] = rot13[j];
                break;  /* Exit the inner loop */
            }
        }
    }

    return (str);
}

