#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <linux/un.h>
#include <string.h>
#include <unistd.h>
void main() {
	int fd;
	int r;
	char buf[100];
	struct sockaddr_un addr = {0};
	//1.����socket
	//fd=socket(AF_UNIX,SOCK_DGRAM,0);
	fd = socket(AF_UNIX,SOCK_STREAM, 0);
	//2.���ӵ�ָ���ĵ�ַ
	addr.sun_family = AF_UNIX;
	memcpy(addr.sun_path, "cs.sock", strlen("cs.sock"));
	r = connect(fd, (struct sockaddr*)&addr, sizeof(addr));
	//3.��������
	while (1) {
		write(fd, "Hello!MaomaoYu!", strlen("Hello!MaomaoYu!"));
		read(fd, buf, 100);
		printf("%s\n", buf);
		sleep(1);	
	}
	//4.�ر�
	close(fd);
	return 0;
}
