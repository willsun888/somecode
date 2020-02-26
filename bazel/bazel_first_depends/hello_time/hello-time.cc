#include "hello_time/hello-time.h"
#include "hello_name/hello-name.h"
#include <ctime>
#include <iostream>

void print_localtime()
{
    std::time_t result = std::time(nullptr);
    std::cout << std::asctime(std::localtime(&result));

    print_name();
}
