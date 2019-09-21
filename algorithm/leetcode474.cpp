#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    pair<int, int> calc01(string& s) {
        pair<int, int> p = make_pair<int, int>(0, 0);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                p.first++;
            } else if (s[i] == '1') {
                p.second++;
            }
        }
        return p;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int> > strv;
        for (int i = 0; i < strs.size(); i++) {
            strv.push_back(calc01(strs[i]));
        }
        for (int i = 0; i < strv.size(); i++) {
            cout << i << ": " << strv[i].first << "," << strv[i].second << endl;
        }
        int dp[101][101];
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                dp[i][j] = 0;
            }
        }
        // for (int k = 0; k < strv.size(); k++) {
        //     pair<int, int> p = strv[k];
        //     for (int i = p.first; i <= m; i++) {
        //         for (int j = p.second; j <= n; j++) {
        //             dp[i][j] = max(dp[i-p.first][j-p.second]+1, dp[i][j]);
        //         }
        //     }
        // }
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k < strv.size(); k++) {
                    pair<int, int> p = strv[k];
                    if (i>=p.first && j>=p.second) {
                        dp[i][j] = max(dp[i-p.first][j-p.second]+1, dp[i][j]);
                    }
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution s;
    vector<string> strs;
    strs.push_back("10");
    strs.push_back("0001");
    strs.push_back("111001");
    strs.push_back("1");
    strs.push_back("0");
    s.findMaxForm(strs, 5, 3);
    return 0;
}
