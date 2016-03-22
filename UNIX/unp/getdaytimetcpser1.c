#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>


int main(int argc, char *argv[]){
	int connfd, listenfd;
	socklen_t len;
	char buf[1024];
	time_t ticks;

	if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) != 0){
		printf("socket error: %m\n");
		return -1;
	}
	struct sockaddr_in addr;
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port(13);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if(bind(listenfd, (struct sockaddr *)&addr, sizeof(addr)) != 0){
		printf("bind error: %m\n");
		return -1;
	}

	if(listen(listenfd, 5) != 0){
		printf("listen error: %m\n");
	}

	while(1){
		int len = sizeof(addr);
		connfd = accept(listenfd, (struct sockaddr *)&addr, &len);
		printf("connection from: %s, port: %d", inet_ntop(AF_INET, &addr->sin_addr, buf,
				 sizeof(buff)), ntohs(addr->sin_port));
		ticks = time(NULL);
		snprintf(buf, sizeof(buf), "%.24\r\n", ctime(&ticks));
		write(connfd, buf, strlen(buf));
		close(connfd);
	}

}



