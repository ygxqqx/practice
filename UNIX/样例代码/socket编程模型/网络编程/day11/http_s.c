#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
int fd,cfd;
main()
{
    char buf[1024];
    int r;
    struct sockaddr_in dr;
    char strres[1024];
    int reused=1;

    fd=socket(PF_INET,SOCK_STREAM,0);
    if(fd==-1) printf("1:%m\n"),exit(-1);
    printf("1\n");
    dr.sin_family=AF_INET;
    dr.sin_port=htons(10000);   
    dr.sin_addr.s_addr=inet_addr("192.168.11.139");
    
    setsockopt(fd,SOL_SOCKET ,SO_REUSEADDR,&reused,sizeof(reused));

    r=bind(fd,(struct sockaddr*)&dr,sizeof(dr));
    if(r==-1) printf("2:%m\n"),exit(-1);
    printf("2\n");
    r=listen(fd,10);
    if(r==-1) printf("3:%m\n"),exit(-1);
    printf("3\n");  
    cfd=accept(fd,0,0); 
    if(cfd==-1) printf("4:%m\n"),exit(-1);
    printf("4\n");
    sprintf(strres,
        "HTTP/1.1 200 OK\r\n"
        "Server: Mozilla/5.0\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: 28\r\n"
        "Connection: keep-alive\r\n"
        "\r\n"
        "<font color=red>靓崽!</font>");
    while(1)
    {
        r=recv(cfd,buf,1024,0);
        if(r>0)
        {
            buf[r]=0;
            printf("recerve data:\n");
            printf("%s\n",buf);
            // recerve data:以下是浏览器访问，给服务器所发的东西
            // GET /index.html HTTP/1.1
            // Host: 192.168.11.139:10000
            // User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux i686; rv:35.0) Gecko/20100101 Firefox/35.0
            // Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
            // Accept-Language: en-US,en;q=0.5
            // Accept-Encoding: gzip, deflate
            // Connection: keep-alive

            //send(cfd,strres,strlen(strres),0);
        }       
        else
        {
            break;
        }
                
    }   
    close(cfd);
    close(fd);
    
}




