#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * op_add - Addition operation
 * @a: First operand
 * @b: Second operand
 *
 * Return: Result of the addition
 */
int op_add(int a, int b)
{
    return (a + b);
}

/**
 * op_sub - Subtraction operation
 * @a: First operand
 * @b: Second operand
 *
 * Return: Result of the subtraction
 */
int op_sub(int a, int b)
{
    return (a - b);
}

/**
 * op_mul - Multiplication operation
 * @a: First operand
 * @b: Second operand
 *
 * Return: Result of the multiplication
 */
int op_mul(int a, int b)
{
    return (a * b);
}

/**
 * op_div - Division operation
 * @a: First operand
 * @b: Second operand
 *
 * Return: Result of the division
 */
int op_div(int a, int b)
{
    return (a / b);
}

/**
 * op_mod - Modulo operation
 * @a: First operand
 * @b: Second operand
 *
 * Return: Result of the modulo operation
 */
int op_mod(int a, int b)
{
    return (a % b);
}

