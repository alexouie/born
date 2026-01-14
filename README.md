*This project has been created as part of the 42 curriculum by almanier.*

# get_next_line

## Description

- The **get_next_line** project consists in implementing a function that reads a line 
- from a file descriptor and returns it one line at a time. Each call returns the next 
- line, including the newline character (`\n`) if present, and preserves unread data 
- between calls without rereading the file.

This project focuses on low-level programming concepts such as:
- Static variables
- Buffer management
- Dynamic memory allocation
- File descriptor handling
- Edge case handling (EOF, errors, empty files)

# ➤ Compilation

To compile the project with your own test file:

```bash
- gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c

**References and documentation used for the project:**
- 42 subject: get_next_line
- man read
- man open
- man close
- https://en.cppreference.com/w/c/io
- Tutorial video: https://youtu.be/U6hEX-rmGYM

**AI usage:**  
- AI was used to:
- Explain variadic functions

All core code, function implementations, and project structure were written manually without AI assistance.

# Additional Sections

## Features
    
- Supports `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`
- Returns the correct number of printed characters

## Usage Examples
/*
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    if (fd < 0)
        return (1);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}

}
*/  
