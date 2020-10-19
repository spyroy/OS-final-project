to compile write in terminal: make

to run open two terminals in the first write: sudo ./policy <pid> <policy> <priority>

if pid not specified than default is - 0 and its the current process.

<policy> is one of the following : 
0 for SCHED_OTHER,
1 for SCHED_FIFO ,
2 for SCHED_RR,
3 for SCHED_BATCH,
5 for  SCHED_IDLE,
6 for  SCHED_DEADLINE.

if priority is not in rage than the default will be SCHED_OTHER with priority 0

after doing so the current process id will apear, to check the policy and priority
write in the second terminal: chrt -p <pid>

range:
SCHED_OTHER min/max priority	: 0/0
SCHED_FIFO min/max priority	: 1/99
SCHED_RR min/max priority	: 1/99
SCHED_BATCH min/max priority	: 0/0
SCHED_IDLE min/max priority	: 0/0
SCHED_DEADLINE min/max priority	: 0/0
