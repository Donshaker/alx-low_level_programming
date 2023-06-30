#include "main.h"
#include <stdio.h>

/**
 * infinite_add - Adds two numbers
 * @n1: The first number
 * @n2: The second number
 * @r: The buffer to store the result
 * @size_r: The size of the buffer
 *
 * Return: Pointer to the result 'r' or 0 if result cannot be stored in 'r'
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int len1 = 0, len2 = 0, carry = 0, sum = 0;
    int i, j, k;

    /* Calculate the lengths of the input numbers */
    while (n1[len1] != '\0')
        len1++;
    while (n2[len2] != '\0')
        len2++;

    if (len1 + 1 > size_r || len2 + 1 > size_r)
        return 0; /* Result cannot be stored in 'r', return 0 */

    /* Perform the addition from right to left */
    i = len1 - 1;
    j = len2 - 1;
    k = size_r - 1;
    while (i >= 0 || j >= 0 || carry != 0)
    {
        sum = carry;
        if (i >= 0)
            sum += n1[i] - '0';
        if (j >= 0)
            sum += n2[j] - '0';

        carry = sum / 10;
        r[k] = (sum % 10) + '0';

        i--;
        j--;
        k--;
    }

    /* Null-terminate the result */
    r[size_r - 1] = '\0';

    /* If there is a leftover carry, shift the result to the right and add 1 to the leftmost position */
    if (carry != 0)
    {
        for (i = size_r - 1; i > 0; i--)
            r[i] = r[i - 1];
        r[0] = carry + '0';
    }

    return (r);
}

