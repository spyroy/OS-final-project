#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc,char* argv[]){
	int pid = atoi(argv[1]);
	kill(pid,0);
	if( errno == EPERM){
		printf("process %d exists but we have no permission ", pid);
	}
	else if( errno == ESRCH){
		printf("process %d does not exists", pid);
	}
	else{
		printf("process %d exists ", pid);
	}
}
