#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int i = 0;

void SIGUSR1_handler(int signum)
{
  	printf("number of signals: %d\n", i);
	printf("restart counter...\n");
	i = 0;
}

void SIGINT_handler(int signum)
{
  	i++;
	printf("got signal \n");
}

int main()
{
	printf("pid: %d\n", getpid());
 	if (signal(SIGINT, SIGINT_handler) == SIG_ERR)
    	{
      		printf("rt\n");
      		exit(0);
    	}
	if (signal(SIGUSR1, SIGUSR1_handler) == SIG_ERR)
    	{
      		printf("rt\n");
      		exit(0);
    	}
  	while (1);
}
