#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned short uint16;
typedef struct ipv6_addr_tag{
    uint16 field1;
    uint16 field2;
    uint16 field3;
    uint16 field4;
    uint16 field5;
    uint16 field6;
    uint16 field7;
    uint16 field8:8;
}ipv6_addr;

int main(int argc, char *argv[])
{
    unsigned char buf[sizeof(struct in6_addr)];
    int domain, s;
    char str[INET6_ADDRSTRLEN];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s {i4|i6|<num>} string\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    domain = (strcmp(argv[1], "i4") == 0) ? AF_INET :
             (strcmp(argv[1], "i6") == 0) ? AF_INET6 : atoi(argv[1]);

    s = inet_pton(domain, argv[2], buf);
    if (s <= 0) {
        if (s == 0)
            fprintf(stderr, "Not in presentation format");
        else
            perror("inet_pton");
        exit(EXIT_FAILURE);
    }
    printf(" buf %s\n", buf );

    if (inet_ntop(domain, buf, str, INET6_ADDRSTRLEN) == NULL) {
        perror("inet_ntop");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", str);
    printf("%d\n", sizeof(uint16) );
    exit(EXIT_SUCCESS);
}
