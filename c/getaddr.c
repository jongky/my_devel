#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 500
static int validate_current_server(const char *current_server)
{
    char *start;
    char *end;
    struct addrinfo hints, *p=0;
    struct addrinfo *result;
    struct sockaddr_in severSock, *h=0;
    int s;
    int error;

    printf("[## JK-DBG-11] validate_current_server : Begin ===>\n");

    if (current_server == NULL) {
        return -1;
    }

    /*
    printf("[## JK-DBG-12.1] validate_current_server : Begin ===>\n");
    if ((start = strstr(current_server, "://")) == NULL) {
        return -1;
    }
    printf("[## JK-DBG-12.2] validate_current_server : start= %s\n", start);
    start+=3;

    printf("[## JK-DBG-13.1] validate_current_server : Begin ===>\n");
    if ((end = strchr(start, ':')) == NULL) {
        printf("[## JK-DBG-13.2] validate_current_server : end= %s\n", end);
        return -1;
    }
    *end = '\x0';
    */
    // start = current_server;
    // printf("resolving host [%s]", start);
    printf ("[## JK-DBG-14] validate_current_server : host [%s]\n", current_server);

    memset(&hints, 0, sizeof(struct addrinfo));
    /* below the family is only AF_INET. getaddrinfo has a memory leak when the family is AF_UNSPEC and it does not free up all used memory.
       AF_UNSPEC sends out request for both A and Quad-A. But AF_INET sends out only for A. getaddrinfo internally does not free up memory allocated
       for Quad-A records.
       So use only AF_INET.
     */
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE;
    hints.ai_protocol = 0;
    hints.ai_canonname = NULL;
    hints.ai_addr = NULL;
    hints.ai_next = NULL;


    if ((error=getaddrinfo("www.google.com", NULL, &hints, (struct addrinfo **)&result)) == 0) {
        p = result;
        h = (struct sockaddr_in *)p->ai_addr;
        char *heh = inet_ntoa(h->sin_addr);
        printf ("[## JK-DBG-15] validate_current_server : Our IP= [%s]\n", heh);
        freeaddrinfo(result);
        // res_init();
        exit(0);
    }
    else {
        printf ("[## JK-DBG-X] validate_current_server : Error= [%s]\n", gai_strerror(error));
        exit(1);
    }
    return 1;
}

int
main(int argc, char *argv[])
{
    char *ip_addr = "www.google.com";
    int rc = 0;

    printf ("[## JK-DBG-01] main : Begin ===>\n");
    printf ("[## JK-DBG-02] main : ip_addr= %s\n", ip_addr);
    rc = validate_current_server(ip_addr);
    printf ("[## JK-DBG-03] main : rc= %x\n", rc);
}