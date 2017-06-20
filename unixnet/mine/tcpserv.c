#include <stdio.h>
#include "unp.h"
#include <sys/socket.h>
#include <netinet/tcp.h>

int main () {
    int listenfd, connfd;
    socklen_t clilen;
    pid_t childpid;
    struct sockaddr_in cliaddr, servaddr;
    listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    int opt;
    socklen_t opt_len;
    int ret = getsockopt(listenfd, IPPROTO_TCP, TCP_MAXSEG, &opt, &opt_len);
    printf("ret:%d, opt:%d, opt_len:%d\n", ret, opt, opt_len);

    int rcv_buf;
    socklen_t rcv_buf_len;
    ret = getsockopt(listenfd, SOL_SOCKET, SO_RCVBUF, &rcv_buf, &rcv_buf_len);
    printf("ret:%d, rcv_buf:%d, rcv_buf_len:%d\n",ret, rcv_buf, rcv_buf_len);

    int snd_buf;
    socklen_t snd_buf_len;
    ret = getsockopt(listenfd, SOL_SOCKET, SO_SNDBUF, &snd_buf, &snd_buf_len);
    printf("ret:%d, snd_buf:%d, snd_buf_len:%d\n",ret, snd_buf, snd_buf_len);

    Bind(listenfd, (SA*)&servaddr, sizeof(servaddr));
    Listen(listenfd, LISTENQ);


    for ( ; ; ) {
         clilen = sizeof(cliaddr);
         connfd = Accept(listenfd, (SA*)&cliaddr, &clilen);
         if ((childpid = Fork()) == 0) {
             Close(listenfd);
             str_echo(connfd);
             exit(0);
         }
         Close(connfd);
    }
    return 0;
}
