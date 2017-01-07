#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>
#include <string.h>


int open_clientfd(char *hostname, int port);

int open_listenfd(int port);



