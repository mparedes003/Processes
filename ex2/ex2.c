// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process.

// Can both the child and parent access the file descriptor returned by `fopen()`?
// Yes

// What happens when they are written to the file concurrently?
// Depending on what the processor chooses at that moment to run first, either parent or child will run before the other

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // open filename text.txt using file access mode for reading
    FILE *fp = fopen("text.txt", "r+");

    // initialize an integer n and assign the value of the system call fork()
    int m = fork();

    // if fork() is 0
    if (m == 0)
    {
        fprintf(fp, "Child says, %s %s\n", "Not", "now.");
    }
    else
    {
        fprintf(fp, "Parent says, %s %s %s %s\n", "Please", "clean", "your", "room.");
    }
    // close stream fp
    fclose(fp);

    return 0;
}
