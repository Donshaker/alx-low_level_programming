#include "main.h"

/**
 * leet - Encodes a string into 1337
 * @str: The string to encode
 *
 * Return: Pointer to the encoded string 'str'
 */
char *leet(char *str)
{
    int i, j;
    char leet_chars[] = "AEOTL";
    char leet_replacements[] = "43071";

    /* Loop through each character of the string */
    for (i = 0; str[i] != '\0'; i++)
    {
        /* Loop through the leet_chars array */
        for (j = 0; leet_chars[j] != '\0'; j++)
        {
            /* Check if the current character matches a leet_char */
            if (str[i] == leet_chars[j] || str[i] == leet_chars[j] + 32)
            {
                /* Replace the character with the corresponding leet replacement */
                str[i] = leet_replacements[j];
                break;  /* Exit the inner loop */
            }
        }
    }

    return (str);
}
