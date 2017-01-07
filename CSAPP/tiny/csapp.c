#include "csapp.h"



int open_clientfd(char *hostname, int port) {

	
	int clientfd;
	if ((clientfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		return -1;
	}
	
	struct hostent *hp;
	if ((hp = gethostbyname(hostname)) == NULL) {
		return -2;
	}
	
	struct sockaddr_in serveraddr;
	bzero((char *)&serveraddr, sizeof(serveraddr));
	
	serveraddr.sin_family = AF_INET;
	bcopy((char *)hp->h_addr_list[0], (char *)&serveraddr.sin_addr.s_addr, hp->h_length);
	serveraddr.sin_port = htons(port);
	
	if (connect(clientfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
		return -1;
	}
	
	return clientfd;
}


int open_listenfd(int port) {
	
	int listenfd, optval = 1;
	
	if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		return -1;
	}
	
	if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int)) < 0) {
		return -1;
	}
	
	struct sockaddr_in serveraddr;
	bzero((char *)&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons((unsigned short)port);
	
	if (bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
		return -1;
	}
	
	if (listen(listenfd, 10) < 0) {
		return -1;
	}
	
	return listenfd;
}














