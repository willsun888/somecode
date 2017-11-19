#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

void test()
{
	#pragma omp parallel
	{
		#pragma omp for nowait
		for (int i = 0; i < 10; ++i)
		{
			cout << "i:" << i << endl;
		}
	}

	cout << "test end" << endl;
}

int main(int argc, char const *argv[])
{
	test();
	return 0;
}