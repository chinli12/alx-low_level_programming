#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "main.h"

int create_file(const char *filename, char *text_content)
{
    int fd, bytes_written, length = 0;

    if (filename == NULL)
        return (-1);

    if (text_content != NULL)
    {
        while (text_content[length])
            length++;
    }

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1)
        return (-1);

    if (text_content != NULL)
    {
        bytes_written = write(fd, text_content, length);
        if (bytes_written != length)
        {
            close(fd);
            return (-1);
        }
    }

    close(fd);
    return (1);
}
