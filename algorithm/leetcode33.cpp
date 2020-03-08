#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int s, int e, int target) {
        cout << "binarySearch:" << " s:" << s << ", e:" << e << endl;
        while (s <= e) {
            int mid = (s+e)/2;
            if (target < nums[mid]) {
                e = mid-1;
            } else if (target > nums[mid]) {
                s = mid+1;
            } else {
                return mid;
            }
        }
        return -1;
    }
    int _search(vector<int>& nums, int s, int e, int target) {
        if (nums.size() == 0) return -1;
        while (s <= e) {
            if (target < nums[s] && target > nums[e]) {
                return -1;
            }
            int mid = (s+e)/2;
            if (target == nums[mid]) {
                return mid;
            }
            cout << "aaaa s:" << s << ", e:" << e << ", mid:" << mid << endl;
            // s   m       e
            // 4 5 6 7 0 1 2
            if (nums[mid] >= nums[s]) {
                if (target < nums[mid] && target >= nums[s]) {  // 二分
                    // return binarySearch(nums, s, mid-1, target);
                    e = mid-1;
                } else {
                    s = mid+1;
                }
            // s       m   e
            // 4 5 6 7 0 1 2
            } else {
                if (target > nums[mid] && target <= nums[e]) {  // 二分
                    // return binarySearch(nums, mid+1, e, target);
                    s = mid+1;
                } else {
                    e = mid-1;
                }
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return _search(nums, 0, nums.size()-1, target);
    }
};

int main()
{
    int target = 1;
    vector<int> nums {3,5,1};
    Solution s;
    cout << s.search(nums, target) << endl;
}
