#include "main.h"

/**
 * is_prime_number - Checks if a number is prime
 * @n: The number to check
 *
 * Return: 1 if the number is prime, 0 otherwise
 */
int is_prime_number(int n)
{
if (n <= 1)  /* Base case: n is not prime */
return (0);

return is_prime_helper(n, 2);
}

/**
 * is_prime_helper - Recursive helper function to check if a number is prime
 * @n: The number to check
 * @divisor: The current divisor to check
 *
 * Return: 1 if the number is prime, 0 otherwise
 */
int is_prime_helper(int n, int divisor)
{
if (divisor >= n)  /* Base case: n is prime */
return (1);

if (n % divisor == 0)  /* Base case: n is not prime */
return (0);

return is_prime_helper(n, divisor + 1);
}

