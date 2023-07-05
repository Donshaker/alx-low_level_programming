#include "main.h"

/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: The number to calculate the square root of
 *
 * Return: The natural square root of the number, or -1 if it does not have a natural square root
 */
int _sqrt_recursion(int n)
{
if (n < 0)  /* Error case: n is negative */
return -1;

return sqrt_helper(n, 0);
}

/**
 * sqrt_helper - Recursive helper function to calculate the square root
 * @n: The number to calculate the square root of
 * @i: The current value to check
 *
 * Return: The square root of the number, or -1 if it does not have a natural square root
 */
int sqrt_helper(int n, int i)
{
if (i * i > n)  /* Base case: no natural square root found */
return -1;

if (i * i == n)  /* Base case: natural square root found */
return i;

return sqrt_helper(n, i + 1);  /* Recursively check the next value */
}

