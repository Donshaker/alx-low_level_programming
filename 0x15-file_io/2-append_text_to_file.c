#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The content to append to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
    int fd, written_bytes, content_length;

    if (filename == NULL)
        return (-1);

    fd = open(filename, O_WRONLY | O_APPEND);
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

