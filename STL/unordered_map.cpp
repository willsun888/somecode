#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * unordered_map中当没有key时，会主动插入pair{str, 0}
 */
void test1()
{
    unordered_map<string, int> mm;
    string ss[] = {"aa", "bb", "cc", "aa", "cc"};
    for (int i = 0; i < 5; i++) {
        ++mm[ss[i]];
    }
    unordered_map<string, int>::iterator it = mm.begin();
    for (; it != mm.end(); it++) {
        cout << "key:" << it->first << ", value:" << it->second << endl;
    }
}

int main()
{
    test1();
    return 0;
}
