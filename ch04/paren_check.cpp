#include <iostream>
#include <stack>
using namespace std;

bool paren_check(const string& s) {
    stack<char> stk;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stk.push(c);
        } else {
            if (stk.empty() ||
                stk.top() == '{' && c != '}' ||
                stk.top() == '(' && c != ')' ||
                stk.top() == '[' && c != ']') {
                return false;
            }
            
            stk.pop();
        }
    }

    return stk.empty();
}

int main() {
    string str1 = "(({[]}))";

    cout << (paren_check(str1) == 1 ? "true" : "false") << endl;
}