#include "main.h"
#include <stdlib.h>

char *str(unsigned int size, char c)
{
if (size == 0)
return (NULL);

char *str = malloc(sizeof(char) * size);
if (str == NULL)
return (NULL);
for (unsigned int i = 0; i < size; i++)
str[i] = c;

return (str);
}

