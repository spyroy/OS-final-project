all: client server

client: client.c
	gcc -Wall -g client.c -o client

server: server.c
	gcc -Wall -g server.c -o server

.phony: clean all

clean:
	rm -f *.o client server
