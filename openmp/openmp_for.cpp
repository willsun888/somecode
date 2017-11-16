#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

void test1() 
{
	cout << __FUNCTION__ << " start" << endl;

	vector<int> iterations(omp_get_max_threads(), 0);
	int n = 100;

	/**
	 this way is ok
	 #pragma omp parallel for shared(iterations, n) 
	 for {}
	 */

	#pragma omp parallel shared(iterations, n)   
	{    
		/**
		 can't be i !=n, which will have error "error: invalid controlling predicate"
		 see blog: http://jakascorner.com/blog/2016/05/omp-for.html
		 */
	    #pragma omp for 
	    for (int i = 0; i < n; i++)    
	    {
	        iterations[omp_get_thread_num()]++;
	    }
	}

	for (size_t i = 0; i < iterations.size(); ++i)
	{
		cout << "thread " << i << " : " << iterations[i] << endl;
	}

	cout << __FUNCTION__ << " end" << endl;
}

void test2() 
{
	cout << __FUNCTION__ << " start" << endl;

	vector<int> iterations(omp_get_max_threads(), 0);
	int n = 100;
  
    #pragma omp for 
    for (int i = 0; i < n; i++)
    {
        iterations[omp_get_thread_num()]++;
    }

	for (size_t i = 0; i < iterations.size(); ++i)
	{
		cout << "thread " << i << " : " << iterations[i] << endl;
	}

	cout << __FUNCTION__ << " end" << endl;
}

int main(int argc, char const *argv[])
{
	test1();
	test2();
	test3();
	return 0;
}

/* output
test1 start
thread 0 : 13
thread 1 : 13
thread 2 : 13
thread 3 : 13
thread 4 : 13
thread 5 : 13
thread 6 : 13
thread 7 : 9
test1 end
test2 start
thread 0 : 100
thread 1 : 0
thread 2 : 0
thread 3 : 0
thread 4 : 0
thread 5 : 0
thread 6 : 0
thread 7 : 0
test2 end
*/