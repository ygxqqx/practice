#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/*
 int socket(int domain, int type, int protocol);
 */

/*
 int bind(int sockfd, const struct sockaddr *my_addr, socklen_t addrlen);

 //man 2 bind
 struct sockaddr {
 sa_family_t sa_family;
 char        sa_data[14];
 }

 //man 7 ip
 struct sockaddr_in {
 sa_family_t    sin_family; // address family: AF_INET
 u_int16_t      sin_port;   // port in network byte order
 struct in_addr sin_addr;   // internet address
 };

 //Internet address.
 struct in_addr {
 u_int32_t      s_addr;     //address in network byte order
 };

 */

//int listen(int sockfd, int backlog);
/*   int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
 On success, accept() returns a non-negative integer that is a descriptor for the accepted socket.   On  error,
 -1 is returned, and errno is set appropriately.
 int conn = 0;
 */
int main() {
	int sockfd = 0;
	//创建socket
	sockfd = socket(PF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		perror("fun socket\n");
		exit(0);
	}
	//定义socket结构体
	struct sockaddr_in srvaddr;
	//设置协议族
	srvaddr.sin_family = AF_INET;
	//设置端口
	srvaddr.sin_port = htons(8001);
	//增加ip地址
	srvaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //127.0.0.1
	//srvaddr.sin_addr.s_addr = htonl(INADDR_ANY); //绑定本机的任意一个地址 
	//绑定IP
	if (bind(sockfd, (struct sockaddr *) &srvaddr, sizeof(srvaddr)) < 0) {
		perror("fun bind\n");
		exit(0);
	}

	//一但调用listen函数，这个套接字sockfd将变成被动套接字;只能接受连接，不能主动的发送连接
	//listen 做了两个队列。。。。。。
	// 队列由内核管理，一部分是完成三次握手的，一部分是没有完成三次握手的。
	if (listen(sockfd, SOMAXCONN) < 0) {
		perror("fun listen\n");
		exit(0);
	}

	//struct sockaddr peeraddr;  //通用ip
	//socklen_t perrlen ;
	struct sockaddr_in peeraddr; //tcpip地址结构
	socklen_t peerlen = sizeof(peeraddr);

	unsigned int conn = 0;
	//accept接受已经完成三次握手的链接，没有链接会阻塞直到有链接
	conn = accept(sockfd, (struct sockaddr *) &peeraddr, (socklen_t *) &peerlen);
	if (conn == -1) {
		perror("fun listen\n");
		exit(0);
	}

	printf("perradd:%s\n perrport:%d\n", inet_ntoa(peeraddr.sin_addr),
			ntohs(peeraddr.sin_port));

	char revbuf[1024] = { 0 };
	while (1) {
		int ret = read(conn, revbuf, sizeof(revbuf));
		if (ret == 0) {
			//如果在读的过程中，对方已经关闭，tcpip协议会返回一个0数据包
			printf("对方已关闭\n");
			exit(0);
		} else if (ret < 0) {

			perror("读数据失败\n");
			exit(0);
		}
		//ssize_t write(int fd, const void *buf, size_t count);
		fputs(revbuf, stdout); //服务器端收到数据，打印屏幕
		write(conn, revbuf, ret); //服务器端回发抱我呢
	}
	return 0;
}
