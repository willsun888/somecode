#include <iostream>
#include <vector>
using namespace std;

int func(const vector<int>& arr) {
    if (arr.size() <= 2) {
        return 0;
    }
    int total = 0, minus = 0;
    int min = 0, max = arr.size()-1;
    if (arr[max] < arr[min]) {
        swap(min, max);
    }
    int range_total = (abs(max-min)-1)*arr[min];
    for (int i = 1; i < arr.size()-1; i++) {
        if (arr[i] <= arr[min]) {
            minus += arr[i];
        } else if (arr[i] < arr[max]) {
            total += (abs(i-min)-1)*arr[min] - minus;
            min = i;
            range_total = (abs(max-min)-1)*arr[min];
            minus = 0;
            cout << "hit 1, i:" << i << ", range_total:" << range_total << endl;
        } else {
            total += (abs(i-min)-1)*arr[min] - minus;
            min = max;
            max = i;
            range_total = (abs(max-min)-1)*arr[min];
            minus = 0;
            cout << "hit 2, i:" << i << ", range_total:" << range_total << endl;
        }
    }
    cout << "end, range_total:" << range_total << ", minus:" << minus << endl;
    total += range_total-minus;
    return total;
}

int main()
{
    int a[] = {3, 0, 1, 6, 0, 5, 7};
    vector<int> arr(&a[0], &a[7]);
    cout << arr.size() << endl;
    cout << func(arr) << endl;
    return 0;
}
