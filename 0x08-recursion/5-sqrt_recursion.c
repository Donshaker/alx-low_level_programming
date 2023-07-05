#include "main.h"

/**
 * sqrt_helper - Recursive helper function to calculate square root
 * @n: The number to calculate the square root of
 * @guess: The current guess for the square root
 *
 * Return: The natural square root of n, or -1 if it doesn't exist
 */
int sqrt_helper(int n, int guess)
{
if (guess * guess == n)
return (guess); /* Found the exact square root */

if (guess * guess > n)
return (-1); /* Square root doesn't exist */

return (sqrt_helper(n, guess + 1)); /* Increment the guess and continue */
}

/**
 * _sqrt_recursion - Calculates the natural square root of a number
 * @n: The number to calculate the square root of
 *
 * Return: The natural square root of n, or -1 if it doesn't exist
 */
int _sqrt_recursion(int n)
{
if (n < 0)
return (-1); /* Square root doesn't exist for negative numbers */

return (sqrt_helper(n, 0));
}

