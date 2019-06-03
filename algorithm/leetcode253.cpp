#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool sortFunc(pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first;
}

void print(vector<pair<int, int> > & timeInterval) {
    for (size_t i = 0; i < timeInterval.size(); i++) {
        cout << "(" << timeInterval[i].first << "," << timeInterval[i].second << ")";
    }
    cout << endl;
}

int meetingRoom(vector<pair<int, int> > & timeInterval) {
    size_t size = timeInterval.size();
    if (!size) return 0;

    sort(timeInterval.begin(), timeInterval.end());

    print(timeInterval);

    priority_queue<int, vector<int>, greater<int> > q;
    q.push(timeInterval[0].second);
    int max = 1;
    int result = 1;
    for (size_t i = 1; i < size; i++) {
        if (!q.empty() && timeInterval[i].first > q.top()) {
            q.pop();
        } else {
            result++;
        }
        q.push(timeInterval[i].second);
    }
    return result;
}

int main()
{
    vector<pair<int, int> > timeInterval;
    timeInterval.push_back(make_pair(30, 40));
    timeInterval.push_back(make_pair(0, 50));
    timeInterval.push_back(make_pair(45, 150));
    int max = meetingRoom(timeInterval);
    cout << "max:" << max << endl;
    return 0;
}
