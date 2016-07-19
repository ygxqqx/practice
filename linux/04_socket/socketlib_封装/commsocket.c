#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "commsocket.h"

typedef struct _SckHandle {
	int sockArray[100];
	int arrayNum;
	int sockfd;
	int contime;
	int sendtime;
	int revtime;

}SckHandle;

/**
 * readn - ��ȡ�̶��ֽ���
 * @fd: �ļ�������
 * @buf: ���ջ�����
 * @count: Ҫ��ȡ���ֽ���
 * �ɹ�����count��ʧ�ܷ���-1������EOF����<count
 */
ssize_t readn(int fd, void *buf, size_t count) {
	size_t nleft = count;
	ssize_t nread;
	char *bufp = (char*)buf;

	while (nleft > 0) {
		if ((nread = read(fd, bufp, nleft)) < 0) {
			if (errno == EINTR) {
				continue;
			}
			return -1;
		} else if (nread == 0) {
			return count - nleft;
		}

		bufp += nread;
		nleft -= nread;
	}

	return count;
}

/**
 * writen - ���͹̶��ֽ���
 * @fd: �ļ�������
 * @buf: ���ͻ�����
 * @count: Ҫ��ȡ���ֽ���
 * �ɹ�����count��ʧ�ܷ���-1
 */
ssize_t writen(int fd, const void *buf, size_t count) {
	size_t nleft = count;
	ssize_t nwritten;
	char *bufp = (char*)buf;

	while (nleft > 0) {
		if ((nwritten = write(fd, bufp, nleft)) < 0) {
			if (errno == EINTR)
				continue;
			return -1;
		} else if (nwritten == 0) {
			continue;
		}

		bufp += nwritten;
		nleft -= nwritten;
	}

	return count;
}

/**
 * recv_peek - �����鿴�׽��ֻ��������ݣ������Ƴ�����
 * @sockfd: �׽���
 * @buf: ���ջ�����
 * @len: ����
 * �ɹ�����>=0��ʧ�ܷ���-1
 */
ssize_t recv_peek(int sockfd, void *buf, size_t len) {
	while (1) {
		int ret = recv(sockfd, buf, len, MSG_PEEK);
		if (ret == -1 && errno == EINTR) {
			continue;
		}
		return ret;
	}
}


//��������
//�ͻ��˻�����ʼ��
int sckCliet_init(void **handle, int contime, int sendtime, int revtime, int nConNum) {
	int 	ret = 0;
	if (handle == NULL ||contime<0 || sendtime<0 || revtime<0) {
		ret = Sck_ErrParam;
		printf("func sckCliet_init() err: %d, check  (handle == NULL ||contime<0 || sendtime<0 || revtime<0)\n", ret);
		return ret;
	}
	
	SckHandle *tmp = (SckHandle *)malloc(sizeof(SckHandle));
	if (tmp == NULL) {
		ret = Sck_ErrMalloc;
		printf("func sckCliet_init() err: malloc %d\n", ret);
		return ret;
	}
	
	tmp->contime = contime;
	tmp->sendtime = sendtime;
	tmp->revtime = revtime;
	tmp->arrayNum = nConNum;
	/*
	int sockfd;
	int i = 0;
	for (i=0; i<1; i++) {
		//�����˳��
		sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (sockfd < 0) {
			ret = errno;
			printf("func socket() err:  %d\n", ret);
			return ret;
		}
		tmp->sockfd = sockfd;
	}
	*/

	*handle = tmp; 
	return ret;
}

/**
 * activate_noblock - ����I/OΪ������ģʽ
 * @fd: �ļ������
 */
int activate_nonblock(int fd) {
	int ret = 0;
	int flags = fcntl(fd, F_GETFL);
	if (flags == -1) {
		ret = flags;
		printf("func activate_nonblock() err:%d", ret);
		return ret;
	}
	
	flags |= O_NONBLOCK;
	ret = fcntl(fd, F_SETFL, flags);
	if (ret == -1) {
		printf("func activate_nonblock() err:%d", ret);
		return ret;
	}
	return ret;
}

/**
 * deactivate_nonblock - ����I/OΪ����ģʽ
 * @fd: �ļ������
 */
int deactivate_nonblock(int fd) {
	int ret = 0;
	int flags = fcntl(fd, F_GETFL);
	if (flags == -1) {
		ret = flags;
		printf("func deactivate_nonblock() err:%d", ret);
		return ret;
	}

	flags &= ~O_NONBLOCK;
	ret = fcntl(fd, F_SETFL, flags);
	if (ret == -1) {
		printf("func deactivate_nonblock() err:%d", ret);
		return ret;
	}
	return ret;
}



/**
 * connect_timeout - connect
 * @fd: �׽���
 * @addr: Ҫ���ӵĶԷ���ַ
 * @wait_seconds: �ȴ���ʱ���������Ϊ0��ʾ����ģʽ
 * �ɹ���δ��ʱ������0��ʧ�ܷ���-1����ʱ����-1����errno = ETIMEDOUT
 */
static int connect_timeout(int fd, struct sockaddr_in *addr, unsigned int wait_seconds) {
	int ret;
	socklen_t addrlen = sizeof(struct sockaddr_in);

	if (wait_seconds > 0) {
		activate_nonblock(fd);
	}

	ret = connect(fd, (struct sockaddr*)addr, addrlen);
	if (ret < 0 && errno == EINPROGRESS) {
		//printf("11111111111111111111\n");
		fd_set connect_fdset;
		struct timeval timeout;
		FD_ZERO(&connect_fdset);
		FD_SET(fd, &connect_fdset);
		timeout.tv_sec = wait_seconds;
		timeout.tv_usec = 0;
		do {
			// һ�����ӽ���,���׽��־Ϳ�д  ����connect_fdset������д������
			ret = select(fd + 1, NULL, &connect_fdset, NULL, &timeout);
		} while (ret < 0 && errno == EINTR);
		if (ret == 0) {
			ret = -1;
			errno = ETIMEDOUT;
		} else if (ret < 0) {
			return -1;
		} else if (ret == 1) {
			//printf("22222222222222222\n");
			/* ret����Ϊ1����ʾ�׽��ֿ�д��,�������������,һ�������ӽ����ɹ�,һ�����׽��ֲ�������*/
			/* ��ʱ������Ϣ���ᱣ����errno������,���,��Ҫ����getsockopt����ȡ.*/
			int err;
			socklen_t socklen = sizeof(err);
			int sockoptret = getsockopt(fd, SOL_SOCKET, SO_ERROR, &err, &socklen);
			if (sockoptret == -1) {
				return -1;
			} if (err == 0) {
				//printf("3333333333333\n");
				ret = 0;
			} else {
				//printf("4444444444444444:%d\n", err);
				errno = err;
				ret = -1;
			}
		}
	}
	if (wait_seconds > 0) {
		deactivate_nonblock(fd);
	}
	return ret;
}



//
int sckCliet_getconn(void *handle, char *ip, int port, int *connfd) {
	
	int ret = 0;
	SckHandle  *tmp = NULL;
	if (handle == NULL || ip==NULL || connfd==NULL || port<0 || port>65537) {
		ret = Sck_ErrParam;
		printf("func sckCliet_getconn() err: %d, check  (handle == NULL || ip==NULL || connfd==NULL || port<0 || port>65537) \n", ret);
		return ret;
	}
	
	//
	int sockfd;
	sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sockfd < 0) {
		ret = errno;
		printf("func socket() err:  %d\n", ret);
		return ret;
	}
	
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = inet_addr(ip);
	
	tmp = (SckHandle* )handle;

	/*
	ret = connect(sockfd, (struct sockaddr*) (&servaddr), sizeof(servaddr));
	if (ret < 0)
    {
    	ret = errno;
		printf("func connect() err:  %d\n", ret);
		return ret;
    }
    */
    
    ret = connect_timeout(sockfd, (struct sockaddr_in*) (&servaddr), (unsigned int )tmp->contime);
    if (ret < 0) {
    	if (ret==-1 && errno == ETIMEDOUT) {
    		ret = Sck_ErrTimeOut;
    		return ret;
    	} else {
    		printf("func connect_timeout() err:  %d\n", ret);
    	}
    }
    
    *connfd = sockfd;
   	return ret;
}



/**
 * write_timeout - д��ʱ��⺯��������д����
 * @fd: �ļ�������
 * @wait_seconds: �ȴ���ʱ���������Ϊ0��ʾ����ⳬʱ
 * �ɹ���δ��ʱ������0��ʧ�ܷ���-1����ʱ����-1����errno = ETIMEDOUT
 */
int write_timeout(int fd, unsigned int wait_seconds) {
	int ret = 0;
	if (wait_seconds > 0) {
		fd_set write_fdset;
		struct timeval timeout;

		FD_ZERO(&write_fdset);
		FD_SET(fd, &write_fdset);

		timeout.tv_sec = wait_seconds;
		timeout.tv_usec = 0;
		do {
			ret = select(fd + 1, NULL, &write_fdset, NULL, &timeout);
		} while (ret < 0 && errno == EINTR);

		if (ret == 0) {
			ret = -1;
			errno = ETIMEDOUT;
		} else if (ret == 1) {
			ret = 0;
		}
	}

	return ret;
}


//�ͻ��˷��ͱ���
int sckClient_send(void *handle, int  connfd,  unsigned char *data, int datalen) {
	int 	ret = 0;
	
	SckHandle  *tmp = NULL;
	tmp = (SckHandle *)handle;
	ret = write_timeout(connfd, tmp->sendtime);
	if (ret == 0) {
		int writed = 0;
		unsigned char *netdata = ( unsigned char *)malloc(datalen + 4);
		if ( netdata == NULL) {
			ret = Sck_ErrMalloc;
			printf("func sckClient_send() mlloc Err:%d\n ", ret);
			return ret;
		}
		int netlen = htonl(datalen);
		memcpy(netdata, &netlen, 4);
		memcpy(netdata+4, data, datalen);
		
		writed = writen(connfd, netdata, datalen + 4);
		if (writed < (datalen + 4) ) {
			if (netdata != NULL) {
				free(netdata);
				netdata = NULL;
			}
			return writed;
		}
		  
	}
	
	if (ret < 0) {
		//ʧ�ܷ���-1����ʱ����-1����errno = ETIMEDOUT
		if (ret == -1 && errno == ETIMEDOUT) {
			ret = Sck_ErrTimeOut;
			printf("func sckClient_send() mlloc Err:%d\n ", ret);
			return ret;
		}
		return ret;
	}
	
	return ret;
}

//�ͻ��˶˽��ܱ���
int sckClient_rev(void *handle,  int  connfd, unsigned char *out, int *outlen) {
	return 0;
}

// �ͻ��˻����ͷ� 
int sckClient_destroy(void *handle) {
	return 0;
}
