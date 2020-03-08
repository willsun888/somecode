#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        if (a == 0 || b == 0) {
            return 1;
        }
        if (a < 0) a = 0-a;
        int c = a>b ? b : a;
        while (a%c != 0 || b%c != 0) {
            c--;
        }
        return c;
    }
    void calc(int op, pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == 0 && a.second == 0) {
            a.first = b.first;
            a.second = b.second;
            if (op == 2) {
                a.first = 0-b.first;
            }
            return;
        }
        int aa = a.first*b.second + a.second*b.first;
        if (op == 2) {
            aa = a.first*b.second - a.second*b.first;
        }
        int bb = a.second*b.second;
        a.first = aa;
        a.second = bb;
    }
    string fractionAddition(string expression) {
        int len = expression.length();
        int i = 0;
        pair<int, int> res = make_pair<int, int>(0, 0);
        while (i < len) {
            int op = 0;
            if (expression[i] == '+') {
                op = 1;
            } else if (expression[i] == '-') {
                op = 2;
            } else {
                op = 1;
                i--;
            }
            if (op > 0) {
                pair<int, int> p = make_pair<int, int>(0, 0);
                p.first = expression[i+1]-'0';
                p.second = expression[i+3]-'0';
                cout << "p.f:" << p.first << ", p.s:" << p.second << endl;
                calc(op, res, p);
                cout << "res.f:" << res.first << ", res.s:" << res.second << endl;
                i += 4;
            } else {
                i++;
            }
        }
        cout << "res.f:" << res.first << ", res.s:" << res.second << endl;
        if (res.first == 0) {
            res.second = 1;
        } else {
        int g = gcd(res.first, res.second);
        res.first = res.first / g;
        res.second = res.second / g;
        }
        ostringstream ss;
        ss << res.first << "/" << res.second;
        return ss.str();
    }
};

int main()
{
    Solution s;
    string res = s.fractionAddition("1/3-1/2");
    cout << "result:" << res << endl;
    return 0;
}
