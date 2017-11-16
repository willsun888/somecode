#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

void test1()
{
	int sum = 0;
	int a[10] = {1,2,3,4,5,6,7,8,9,10};

	#pragma omp parallel for shared(sum, a)
	for (int i = 0; i < 10; ++i)
	{
		sum += a[i];
	}

	cout << "sum:" << sum << endl;
}

void test2()
{
	int sum = 0;
	int a[10] = {1,2,3,4,5,6,7,8,9,10};

	#pragma omp parallel for shared(a) reduction(+:sum)
	for (int i = 0; i < 10; ++i)
	{
		sum += a[i];
	}

	cout << "sum:" << sum << endl;
}

int main(int argc, char const *argv[])
{
	test1();
	test2();
	return 0;
}

/**
output:
sum:52  // uncertain sum
sum:55
*/