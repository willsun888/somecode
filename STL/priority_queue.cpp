#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;


/**
默认比较函数为less, 大顶堆
**/
void defaultCmpLess() {
    cout << "=========defaultCmpLess(big heap)========" << endl;
    priority_queue<int> q;
    for (int i = 0; i < 10; i++) {
        q.push(rand()%20);
    }

    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout <<endl;

}

int main()
{
    defaultCmpLess();
    return 0;
}
