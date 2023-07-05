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

return sqrt_helper(0);
}

/**
 * sqrt_helper - Recursive helper function to calculate the square root
 * @n: The number to calculate the square root of
 * @low: The lower bound for searching
 * @high: The upper bound for searching
 *
 * Return: The square root of the number, or -1 if it does not have a natural square root
 */
int sqrt_helper(int n, int low, int high)
{
int mid = (low + high) / 2;

if (low > high)  /* Base case: no natural square root found */
return -1;

if (mid * mid == n)  /* Base case: natural square root found */
return mid;

if (mid * mid > n)  /* Search in the lower half */
return sqrt_helper(n, low, mid - 1);

/* Search in the upper half */
return sqrt_helper(n, mid + 1, high);
}

