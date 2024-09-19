#include <iostream>
#include <stack>
#include <vector>
using namespace std;

string reverse(const string& str) {
    stack<char> stk;
    for (auto c : str) {
        stk.push(c);
    }

    string res;

    while(!stk.empty()) {
        res += stk.top();
        stk.pop();
    }
    
    

    return res;
}

template <typename T>
void reverse(vector<T>& vec) {
    stack<T, vector<T>> stk(vec);

    //stack<T> stk;
    /*for (const auto& e : vec) {
        stk.push(e);
    }*/

    for (int i = 0; i < vec.size(); i++) {
        vec[i] = stk.top();
        stk.pop();
    }
}

int main() {
    string str = "hello";
    cout << reverse(str) << endl;

    vector<int> vec {10, 20, 30, 40, 50};

    reverse<int>(vec);

    for (auto e : vec) {
        cout << e << " ";
    }
    cout << endl;
}