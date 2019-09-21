#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tmp = -1;
        int i = 0;
        while (true) {
            if (nums[i] == i+1) {
                nums[i] = -nums[i];
                i++;
            }
            if (nums[i] < 0) {
                return 0-nums[i];
            }
            tmp = nums[nums[i]-1];
            cout << "i:" << i << ", tmp:" << tmp << endl;
            nums[nums[i]-1] = 0-nums[i];
            i = tmp-1;
            sleep(1);
        }
        return 0-tmp;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(2);
    cout << s.findDuplicate(nums) << endl;
}
