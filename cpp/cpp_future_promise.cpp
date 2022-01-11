#include <iostream>       // std::cout
#include <functional>     // std::ref
#include <thread>         // std::thread
#include <future>         // std::promise, std::future

void test() {
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();

}

int main() {
    return 0;
}
