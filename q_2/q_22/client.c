#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int     main(int argc, char** argv)
{
 	int   i = 0;
  	if (argc < 4)
    		exit(2);
	if(atoi(argv[2]) == 10){
		for(i = 0; i < atoi(argv[3]);i++){
			printf("print numbers of signals got in server (look on server) \n");
			kill(atoi(argv[1]), SIGUSR1);
		}
	}
	if(atoi(argv[2]) == 2){
		for(i = 0; i < atoi(argv[3]);i++){
			printf("send signal number: %d\n", i+1);
			kill(atoi(argv[1]), SIGINT);
		}
	}
  	//kill(atoi(av[1]), SIGUSR2);
	return 0;
}
