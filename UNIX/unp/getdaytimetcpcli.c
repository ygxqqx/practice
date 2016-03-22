#include <sys/socket.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]){

    struct sockaddr_in addr;
    int fd, n;
    char recvline[1024+1];
    if(argc != 2)
        printf("enter ipaddr\n");

    if((fd = socket(AF_INET, SOCK_STREAM,0)) < 0){
        printf("socket err\n");
        return -1;
    }

    bzero(&addr, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(13);//day time server
    if(inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0){
        printf("inet_pton err:%m\n");
        return -1;
    }
        

    if(connect(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0){
        printf("connect err:%m\n");
        return -1;
    }

    while((n = read(fd, recvline, 1024))){
        recvline[n] = 0;
        if(fputs(recvline, stdout) == EOF){
        	printf("fputs err");
        }
    }
    if(n < 0)
    	printf("read err\n");
    exit(0);
}



