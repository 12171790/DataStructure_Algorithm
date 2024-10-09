#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> d;

    d.push_front(10);
    d.push_front(20);
    d.push_front(30);

    d.push_back(40);
    d.push_back(50);
    d.push_back(60);

    while(!d.empty()) {
        cout << d.front() << " ";
        d.pop_front();
    }

    cout << endl;
}