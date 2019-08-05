#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ip2int(const char* ip)
{
    if (!ip) return 0;
    int num = 0;
    const char *p = ip, *q = ip;
    do {
        if (*p == '.' || *p == '\0') {
            char r[4] = {0, 0, 0, 0};
            strncpy(r, q, p-q);
            num = num*256 + atoi(r);
            q = p+1;
        }
        if (*p != '\0') {
            ++p;
        } else {
            break;
        }
    } while(1);
    return num;
}

int ip2int2(const char* ip)
{
    char* s = strdup(ip);
    char* t = strtok(s, ".");
    int num = 0;
    while (t) {
        num = num*256 + atoi(t);
        t = strtok(NULL, ".");
    }
    free(s);
    return num;
}

int main(int argc, char** argv)
{
    printf("%d\n", ip2int(argv[1]));
    printf("%d\n", ip2int2(argv[1]));
    return 0;
}
