#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <errno.h>

void sig_chld(int signo){
	pid_t pid;
	int stat;
	while((pid = waitpid(-1, &stat, WNOHANG)) > 0)
		printf("child: %d terminated\n", pid);
	return;
}

void str_echo(int fd){
	char buf[1025];
	int n;

again:
	while((n = read(fd, buf, 1024)) > 0){
		write(fd, buf, n);
	}

	if(n < 0 && errno == EINTR)
		goto again;
	else if(n < 0)
		printf("read errno: %m\n");

}


int main(){
	int sockfd, accefd;
	struct sockaddr_in addr;
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) != 0){
		printf("sock errno: %m\n");
		return -1;
	}
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(6666);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) != 0){
		printf("bind err: %m\n");
		return -1;
	}

	listen(sockfd, 6);
	signo(SIGCHLD, sig_chld);
	
	while(1){
		int len = sizeof(addr);
		if((accefd = accept(sockfd, (struct sockaddr *)&addr, &len)) < 0){
			if(errno == ENITR)
				continue;
			else
				printf("connect error\n");
		}
		if(fork() == 0){
			close(sockfd);
			str_echo(accefd);
			exit(0);
		}
		
		close(accefd);
	}
}