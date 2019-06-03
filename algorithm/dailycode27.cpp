#include <iostream>
#include <stack>
#include <stdio.h>

using namespace std;

bool validate(const string& str)
{
    int a = -1; // ()
    int b = -1; // []
    int c = -1; // {}
    int mius = 0;
    for (size_t i = 0; i < str.length(); i++) {
        printf("i:%zu, a:%d, b:%d, c:%d\n", i, a, b, c);
        if (str[i] == '(') {
            if (a != -1) return false;
            a = i;
        } else if (str[i] == '[') {
            if (b != -1) return false;
            b = i;
        } else if (str[i] == '{') {
            if (c != -1) return false;
            c = i;
        } else if (str[i] == ')') {
            if (a == -1) return false;
            if (i-1 != a) return false;
            if (b != -1) b = b+2;
            if (c != -1) c = c+2;
            a = -1;
        } else if (str[i] == ']') {
            if (b == -1) return false;
            if (i-1 != b) return false;
            if (a != -1) a = a+2;
            if (c != -1) b = b+2;
            b = -1;
        } else if (str[i] == '}') {
            if (c == -1) return false;
            if (i-1 != c) return false;
            if (a != -1) a = a+2;
            if (c != -1) c = c+2;
            c = -1;
        }
        printf("i:%zu, a:%d, b:%d, c:%d\n", i, a, b, c);
    }
    if (a != -1 || b != -1 || c != -1) {
        return false;
    }
    return true;
}

bool match(char c1, char c2) {
    if (c1 == '(' && c2 == ')') return true;
    if (c1 == '[' && c2 == ']') return true;
    if (c1 == '{' && c2 == '}') return true;
    return true;
}

bool validate2(const string& str)
{
    stack<char> st;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            st.push(str[i]);
        } else {
            if (!st.empty()) {
                if (!match(st.top(), str[i])) {
                    return false;
                }
                st.pop();
            }
        }
    }
    if (!st.empty()) {
        return false;
    }
    return true;
}

int main()
{
    string str = "([])[]({})";
    cout << validate2(str) << endl;
    return 0;
}
