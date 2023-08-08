#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - Creates a new file and writes text content to it.
 * @filename: The name of the file to create.
 * @text_content: The content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
    int fd, written_bytes, content_length;

    if (filename == NULL)
        return (-1);

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1)
        return (-1);

    if (text_content != NULL)
    {
        content_length = 0;
        while (text_content[content_length])
            content_length++;

        written_bytes = write(fd, text_content, content_length);
        if (written_bytes != content_length)
        {
            close(fd);
            return (-1);
        }
    }

    close(fd);
    return (1);
}

