/**
 * int_index - Searches for an integer in an array.
 * @array: Pointer to the integer array.
 * @size: Number of elements in the array.
 * @cmp: Pointer to the function used to compare values.
 *
 * Return: Index of the first element for which cmp function does not return 0,
 *         or -1 if no element matches or if size <= 0.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
    /* Check for invalid input */
    if (array == NULL || cmp == NULL || size <= 0)
        return -1;

    int i;

    /* Iterate through the array and search for the integer */
    for (i = 0; i < size; i++)
    {
        if (cmp(array[i]) != 0)
            return i;
    }

    /* If no element matches, return -1 */
    return -1;
}

