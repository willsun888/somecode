#include <iostream>
using namespace std;
class Solution {
public:
    string customSortString(string S, string T) {
    static    const int N = 27;
    static    int tt[N];
    //    for (int i = 0; i < N; i++) {
    //        tt[i] = 0;
    //    }
        int lenT = T.length();
        for (int i = 0; i < lenT; i++) {
            tt[T[i]-'a'] += 1;
        }
        string res;
        int lenS = S.length();
        for (int i = 0; i < lenS; i++) {
            int n = tt[S[i]-'a'];
            for (int j = 0; j < n; j++) {
                res.append(string(1, S[i]));
                tt[S[i]-'a'] -= 1;
            }
        }
        cout << "res:" << endl;
        for (int i = 0; i < N; i++) {
            int n = tt[i];
            for (int j = 0; j < n; j++) {
                res.append(string(1, i+'a'));
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    string S = "cba";
    string T = "aabccd";
    cout << s.customSortString(S, T) << endl;
    return 0;
}
