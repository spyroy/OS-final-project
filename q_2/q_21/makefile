all: pid

pid: check_pid.c
	gcc -Wall -g check_pid.c -o pid

.phony: clean all

clean:
	rm -f *.o pid
