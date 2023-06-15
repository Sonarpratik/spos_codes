/* pid = 0 - child
  pid > 0 - parent
  pid < 0 - fork failed

#include <sys/types.h> -  all type def sysmbols
#include <unistd.h> - provide access of os


orphan
child process in running
parent work is done and its gone is called orphan


zombie
task is completed but entry is in table is called zombie
A process which has finished the execution but still has entry in the process table to report to its parent
process is known as a zombie process. A child process always first becomes a zombie before being removed from
the process table. The parent process reads the exit status of the child process which reaps off the child
process entry from the process table.


pid_t pid;      // data type - variable name
pid = fork();    //fork - new process

*/

// zombie
#include <stdio.h>
#include <sys/types.h>
// #include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid; // datatype pid_t
    pid = fork();
    if (pid == -1)
    {
        printf("Fork Failed!!\n");
    }
    else if (pid == 0)
    {
        printf(" I am Child process ID is :: %d and my parent process ID is :: %d ", getpid(), getppid());
    }
    else
    {
        // wait(NULL);
        sleep(3);
        printf("\nI am Parent process ID is :: \"%d\" and may child process ID is :: \"%d\" \n", getpid(), pid);
    }

    return 0;
}

// orphan
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    pid = fork();
    // printf("%d\n",pid);
    if (pid == 0)
    {
        printf("child process is created and process id id %d \n my parent process id is   %d", getpid(), getppid());
        printf("Chlid process id before sleep\n");
        sleep(2);

        printf("child process id after sleep\n");
        printf("child process is created and process id id %d \n my parent process id is %d", getpid(), getppid());
    }
    else
    {
        printf("parent process id is %d \n my parent process id is %d ", getpid(), getppid());
        _exit(0);
    }
    return 0;
}

// zombie another code
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    pid = fork();
    // printf("%d\n",pid);
    if (pid == 0)
    {
        printf("child process is created and process id id %d \n my parent process id is      %d", getpid(), getppid());
        _exit(0);
    }
    else
    {
        sleep(2);
    }
    return 0;
}
