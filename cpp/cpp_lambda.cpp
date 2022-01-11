#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void hello_world() {
    [](){ cout << "hello world" << endl; }();
    auto hw = [](){ cout << "hello world" << endl; };
    hw();
    cout << "========" << endl;
}

void return_value() {
    // decltype guess return type
    auto func1 = [](int a, int b) { return a + b; };
    cout << func1(3, 4) << endl;
    auto func2 = [](int a, int b) -> int { return a + b; };
    cout << func2(3, 4) << endl;
    cout << "========" << endl;
}

void capture_param() {
    int num = 100;
    // read only
    auto fun1 = [=](){ cout << num << endl; };
    fun1();
	cout << num << endl;
    cout << "========" << endl;
	int tt = 100;
    // read and write
    auto fun2 = [&, tt]() mutable { num = 200; tt = 200; cout << "num=" << num << endl; };
    fun2();
    cout << "num=" << num << endl; // num = 200
    cout << "tt=" << tt << endl; // tt = 100
    cout << "========" << endl;
	cout << &fun2 << endl;
    cout << "========" << endl;
}

void modify_vector() {
	vector<int> v = {1, 2, 3, 4, 5};
	for_each(v.begin(), v.end(), [](int& i){ i += 1; });
	cout << "iterator vector" << endl;
	for_each(v.begin(), v.end(), [](int i){ cout << i << endl; });
    cout << "========" << endl;
}

int main() {
    hello_world();
    return_value();
	capture_param();
	modify_vector();
    return 0;
}
