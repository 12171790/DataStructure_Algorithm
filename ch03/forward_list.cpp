#include <iostream>
#include <forward_list>
using namespace std;

int main() {
    forward_list<int> l1 {10, 20, 30, 40};
    l1.push_front(50);
    l1.push_front(60);

    for (auto n : l1) {
        cout << n << " ";
    }
    cout << endl;

    int cnt = distance(l1.begin(), l1.end());

    cout << cnt << endl;

    l1.remove(40);
    l1.remove_if([](int n) {return n > 40;});

    for (auto n : l1) {
        cout << n << " ";
    }
    cout << endl;
}