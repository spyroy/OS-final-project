#include <sched.h>
#include <stdio.h>
#include <string.h>
#include <linux/sched.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <linux/unistd.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <pthread.h>

#define _GNU_SOURCE

#ifdef __x86_64__
#define __NR_sched_setattr		314
#define __NR_sched_getattr		315
#endif

#ifdef __i386__
#define __NR_sched_setattr		351
#define __NR_sched_getattr		352
#endif

#ifdef __arm__
#define __NR_sched_setattr		380
#define __NR_sched_getattr		381
#endif

struct sched_attr {
	__u32 size;
	__u32 sched_policy;
	__u64 sched_flags;
	__s32 sched_nice;
	__u32 sched_priority;
	__u64 sched_runtime;
	__u64 sched_deadline;
	__u64 sched_period;
};

int main (int argc, char** argv)
{
   	struct sched_param param;
	struct sched_attr attr;
	attr.size = sizeof(attr);
	attr.sched_flags = 0;
	attr.sched_nice = 0;
	attr.sched_priority = 0;
	attr.sched_policy = SCHED_DEADLINE;
	attr.sched_runtime = 10 *1000;
	attr.sched_period = attr.sched_deadline = 30 *1000 ;
	printf("my pid is %d\n",getpid());
	if(argc == 4){
   		int pid_num = atoi(argv[1]);
		int sched = atoi(argv[2]);
		int priority = atoi(argv[3]);
   		param.sched_priority = priority;
		if(sched == 6){
			//sched_setscheduler(pid_num, SCHED_DEADLINE, &param);
			syscall(__NR_sched_setattr, pid_num, &attr, 0);
			printf("schedualing is deadline and priority %d\n",priority);
		}
		if(sched == 3){
			sched_setscheduler(pid_num, SCHED_BATCH, &param);
			printf("schedualing is batch and priority %d\n",priority);
		}
		if(sched == 1){
			sched_setscheduler(pid_num, SCHED_FIFO, &param);
			printf("schedualing is fifo and priority %d\n",priority);
		}
		if(sched == 5){
			sched_setscheduler(pid_num, SCHED_IDLE, &param);
			printf("schedualing is idle and priority %d\n",priority);
		}
		if(sched == 2){
			sched_setscheduler(pid_num, SCHED_RR, &param);
			printf("schedualing is rr and priority %d\n",priority);
		}
		if(sched == 0 || sched > 6){
			sched_setscheduler(pid_num, SCHED_OTHER, &param);
			printf("schedualing is other and priority %d\n",priority);
		}
   		while (1) ;
	}
	else if(argc == 3){ //pid = 0
		int pid_num = 0;
		int sched = atoi(argv[1]);
		int priority = atoi(argv[2]);
   		param.sched_priority = priority;
		if(sched == 6){
			//sched_setscheduler(pid_num, SCHED_DEADLINE, &param);
			syscall(__NR_sched_setattr, pid_num, &attr, 0);
			printf("schedualing is deadline and priority %d\n",priority);
		}
		if(sched == 3){
			sched_setscheduler(pid_num, SCHED_BATCH, &param);
			printf("schedualing is batch and priority %d\n",priority);
		}
		if(sched == 1){
			sched_setscheduler(pid_num, SCHED_FIFO, &param);
			printf("schedualing is fifo and priority %d\n",priority);
		}
		if(sched == 5){
			sched_setscheduler(pid_num, SCHED_IDLE, &param);
			printf("schedualing is idle and priority %d\n",priority);
		}
		if(sched == 2){
			sched_setscheduler(pid_num, SCHED_RR, &param);
			printf("schedualing is rr and priority %d\n",priority);
		}
		if(sched == 0 || sched > 6){
			sched_setscheduler(pid_num, SCHED_OTHER, &param);
			printf("schedualing is other and priority %d\n",priority);
		}
		// keep this process running
   		while (1) ;
	}
	return 0;
}
