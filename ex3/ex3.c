// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // initialize character pointer child and assign the value of the string "hello"
    char *child = "hello";
    // initialize character pointer parent and assign the value of the string "goodbye"
    char *parent = "goodbye";

    // initialize pid_t pointer pid and assign the value of the system call fork()
    pid_t pid = fork();

    // if fork() is not equal to 0
    if (pid != 0)
    {
        // initialize an integer wc and assign the value of the system call waitpid()
        int wc = waitpid(pid, NULL, 0);
        printf("Parent prints, %s\n", parent);
    }
    else
    {
        printf("Child prints, %s\n", child);
    }

    return 0;
}
