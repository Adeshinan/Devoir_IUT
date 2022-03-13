#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
  int pid = fork();
    if (pid < 0)
    {
        printf("Erreur de fork\n");
        return 1;
    }
    if (pid == 0)
    {
       printf("Je suis le fils (%d), mon père\n", getppid());
    }
    else
    {
        printf("Je suis le père (%d), mon fils ", getpid());
    }
return 0;
}
