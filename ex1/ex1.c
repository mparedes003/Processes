// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100).

// What value is the variable in the child process?
// int m = 500. Same as in the parent.

// What happens to the variable when both the child and parent change the value of x?
// Child increments by 1 as instructed in m++
// Parent decrements by 1 as instructed in m--

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // initialize an integer m and assign the value of 500
    int m = 500;
    // initialize an integer n and assign the value of the system call fork()
    int n = fork();

    // if fork() is 0
    if (n == 0)
    {
        printf("Child is m = %d\n", ++m);
    }
    else
    {
        printf("Parent is m = %d\n", --m);
    }

    return 0;
}
