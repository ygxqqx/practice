#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void main() {
	int fd;
	int r;
	char buf[200];
	//1.建立socket
	//2
	fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (fd == -1) {
		printf("socket err:%m\n");
		exit(-1);
	}
	printf("socket成功!\n");
	//2.构造本地文件地址
	//3.
	struct sockaddr_in addr = {0};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9999);
	addr.sin_addr.s_addr = inet_addr("192.168.180.92");
	//3.把socket绑定在地址上
	r = bind(fd, (struct sockaddr*)&addr, sizeof(addr));
	if (r == -1) {
		printf("bind err:%m\n");
		exit(-1);
	}
	printf("地址绑定成功!\n");
	
	//4.接收数据
	while (1) {
		bzero(buf, sizeof(buf));
		r = read(fd, buf, sizeof(buf));
		buf[r] = 0;
		printf("%s\n", buf);
	}	
	
	//5.关闭
	close(fd);
	//6.删除socket文件
	unlink("my.sock");
	return 0;
}
