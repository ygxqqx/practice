#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <strings.h>
#include <arpa/inet.h>


void str_cli(FILE *fp, int fd){
	char sendline[1025], recvline[1025];
	int n;
	while(fgets(sendline, 1024, fp) != NULL){
		if((n = read(fd, recvline, 1024)) > 0)
			fputs(recvline, stdout);
		else{
			printf("recv errno: %m\n");
			return;
		}
	}
}



int main(int argc,char *argv[]){
	int  sockfd, connfd;
	struct sockaddr_in addr;

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) != 0){
		printf("socket errno%m\n");
		return -1;
	}

	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(6666);
	inet_pton(AF_INET, argv[1], &addr.sin_addr);

	connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
	str_cli(stdin, sockfd);
}

