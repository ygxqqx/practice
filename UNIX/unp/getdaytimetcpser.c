#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>


int main(int argc, char *argv[]){
	int fd, connfd;
	char buf[1024+1];
	struct sockaddr_in addr;
	time_t ticks;

	if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		printf("%m\n");
		return -1;
	}

	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(13);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(fd, (struct sockaddr *)&addr, sizeof(addr));

	listen(fd, 5);

	while(1){
		connfd = accept(fd,NULL,NULL);

		ticks = time(NULL);
		snprintf(buf, sizeof(buf), "%.24s\r\n", ctime(&ticks));
		write(connfd, buf, strlen(buf));
		close(connfd);
	}
}



