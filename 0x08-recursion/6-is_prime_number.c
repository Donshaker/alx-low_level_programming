#include "main.h"

/**
 * check_divisibility - Checks if an integer is divisible by a given divisor
 * @n: The integer to check
 * @divisor: The divisor to check against
 *
 * Return: 1 if n is divisible by divisor, 0 otherwise
 */
int check_divisibility(int n, int divisor)
{
if (n == divisor)
return (1); /* n is prime */
if (n % divisor == 0 || n < 2)
return (0); /* n is divisible by divisor or n is not prime */
return (check_divisibility(n, divisor + 1)); /* Recursive call */
}

/**
 * is_prime_number - Checks if an integer is a prime number
 * @n: The integer to check
 *
 * Return: 1 if the integer is a prime number, 0 otherwise
 */
int is_prime_number(int n)
{
if (n <= 1)
return (0); /* 0 and 1 are not prime numbers */
return (check_divisibility(n, 2));
}




