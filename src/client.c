#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<errno.h>
#include<string.h>
#include<sys/socket.h>

#define MAXLINE 4096
int main(int argc,char** argv){
    int socketFd,n;
    struct sockaddr_in serverAddress;
    char recvLine[4096],sendLine[4096];

    if(argc != 2){
        printf("usage: ./client <ipaddress>\n");
        exit(0);
    }

    if((socketFd = socket(AF_INET,SOCK_STREAM,0)) < 0){
        printf("create socket error:%s(errNo: %d)\n",strerror(errno),errno);
        exit(0);
    }

    memset(&serverAddress,0,sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    if( inet_pton(AF_INET, argv[1], &serverAddress.sin_addr) < 0){
        printf("inet-pton error for %s\n",argv[1]);
        exit(0);
    }
    if( connect(socketFd,(struct sockaddr*)&serverAddress,sizeof(serverAddress)) < 0){
        printf("connect socket error:%s(errNo: %d)\n",strerror(errno),errno);
        exit(0);
    }
    while (1){
        printf("send message to server:\n");
        sendLine[0]='\0';
        fgets(sendLine,4096,stdin);

        if (send(socketFd,sendLine,strlen(sendLine),0) < 0){
            printf("send socket error:%s(errNo: %d)\n",strerror(errno),errno);
            exit(0);
        }
        printf("after Send\n");
    }
    
    
    close(socketFd);
    exit(0);
}