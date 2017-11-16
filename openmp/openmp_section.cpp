#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

void func1() 
{
	cout << "func1 start" << endl;
	for (int i = 0; i < 3; ++i)
	{
		cout << "func1:" << i << endl;
		sleep(1);
	}
	cout << "func1 end" << endl;
}

void func2()
{
	cout << "\tfunc2 start" << endl;
	for (int i = 0; i < 2; ++i)
	{
		cout << "\tfunc2:" << i << endl;
		sleep(2);
	}
	cout << "\tfunc2 end" << endl;
}

void test()
{
    #pragma omp parallel sections
    {    
        #pragma omp section
        func1();
            
        #pragma omp section
        func2();
    }
}

int main(int argc, char const *argv[])
{
	test();
	return 0;
}