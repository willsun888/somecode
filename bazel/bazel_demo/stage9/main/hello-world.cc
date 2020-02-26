#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#include "main/hello-local.h"
#include "hello_time/hello-time.h"
#include "static1.0/hello-echo.h"

int main(int argc, char** argv)
{
    char* hi = "hello world!\n";
    local(hi);
    print_localtime();
    print_echo();
    return 0;
}
