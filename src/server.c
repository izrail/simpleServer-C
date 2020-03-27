#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<errno.h>
#include<string.h>
#include<sys/socket.h>

#define MAXLINE 4096
int main(){
    int socketFd,connFd;
    struct sockaddr_in serverAddress;
    char buffer[4096];
    int n; 
    //指定socket的协议
    if((socketFd = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
        printf("create socket error:%s(errNo: %d)\n",strerror(errno),errno);
        exit(0);
    }

    memset(&serverAddress,0,sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(8080);

    if( bind(socketFd,(struct sockaddr*)&serverAddress,sizeof(serverAddress)) < 0){
        printf("bind socket error:%s(errNo: %d)\n",strerror(errno),errno);
        exit(0);
    }

    if (listen(socketFd,10) < 0){
        printf("listen socket error:%s(errNo: %d)\n",strerror(errno),errno);
        exit(0);
    }
    while (1){
        printf("test1\n");
        if ( (connFd = accept(socketFd,(struct sockaddr*)NULL,NULL)) < 0){
            printf("accept socket error:%s(errno: %d\n",strerror(errno),errno);
            continue;
        }
    }
    while (1)
    {
        printf("test buffer:\n%s shenme\n",buffer);
        n = recv(connFd,buffer,MAXLINE,0);
        buffer[n] ='\0';
        printf("recive message from client:\n%s shenme",buffer);
        printf("test2\n\n\n");
    }
    close(connFd);
    close(socketFd);
}