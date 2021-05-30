#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>


struct golem{
    int i;
    int b;
};

void getValue(int *my_pointer){
    *my_pointer = 1000; // using address
}

int main() {
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr;

    char sendBuff[1025];
    time_t ticks;

    listenfd = socket(AF_INET, SOCK_STREAM, 0); // создание неименнованого сокета
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000);

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    listen(listenfd, 10);

    while(1){
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
        ticks = time(NULL);
        snprintf(sendBuff, sizeof(sendBuff), "%.24s\r\n", ctime(&ticks));
        write(connfd, sendBuff, strlen(sendBuff));
        close(connfd);
        sleep(1);

    }


    return 0;
}

int lol() {
    int num = 25;
    float x;
    x = 4.56f;
    char sym = 'A';
    struct golem nikita;
    nikita.i = 1;
    printf("%d\n", nikita.i);
    double y = 6.1231415131;
    printf("Num is %d, x is %.2f\n", num, x); // %d - for decimal format, %f,%s

    int get_value;
    getValue(&get_value);
    printf("%d", get_value); //address
    return 0;
}
