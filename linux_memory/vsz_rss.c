#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <malloc.h>

char ps_cmd[1024];

void print_info(char* var_name, char* var_ptr, size_t size_in_kb)
{
    printf("Address of %s(%luk) 0x%lx,  now heap top is 0x%lx\n",
                        var_name, size_in_kb, var_ptr, sbrk(0));
    system(ps_cmd);
}

int main(int argc, char** argv)
{
        char *non_set_var, *set_1k_var, *set_5k_var, *set_7k_var;

        pid_t pid;
        pid = getpid();

        sprintf(ps_cmd, "ps aux | grep %lu | grep -v grep", pid);

        non_set_var = malloc(32*1024);
        print_info("non_set_var", non_set_var, 32);

        set_1k_var = malloc(64*1024);
        memset(set_1k_var, 0, 1024);
        print_info("set_1k_var", set_1k_var, 64);

        set_5k_var = malloc(127*1024);
        memset(set_5k_var, 0, 5*1024);
        print_info("set_5k_var", set_5k_var, 127);

        set_7k_var = malloc(64*1024);
        memset(set_1k_var, 0, 7*1024);
        print_info("set_7k_var", set_7k_var, 64);

        return 1;
}

/**
Address of non_set_var(32k) 0x1947010,  now heap top is 0x1970000
606       7305  0.0  0.0   7256   348 pts/7    S+   18:04   0:00 ./a.out
Address of set_1k_var(64k) 0x194f020,  now heap top is 0x1970000
606       7305  0.0  0.0   7256   348 pts/7    S+   18:04   0:00 ./a.out
Address of set_5k_var(127k) 0x195f030,  now heap top is 0x199f000
606       7305  0.0  0.0   7444   556 pts/7    S+   18:04   0:00 ./a.out
Address of set_7k_var(64k) 0x197ec40,  now heap top is 0x199f000
606       7305  0.0  0.0   7444   556 pts/7    S+   18:04   0:00 ./a.out
*/
