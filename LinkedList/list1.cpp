#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);

    list<int> l2 {10, 20, 30, 40};

    for (auto n : l1) {
        cout << n << " ";
    }
    cout << endl;

    for (auto n : l2) {
        cout << n << " ";
    }
    cout << endl;

    l2.splice(l2.end(), l1); // l2의 마지막 위치에 l1의 원소를 모두 이어 붙여라.
    // l1의 데이터가 복사되는 것이 아닌 이동되는 것이므로 l1은 비게됨.

    for (auto n : l2) {
        cout << n << " ";
    }
    cout << endl;

    l2.sort();

    for (auto n : l2) {
        cout << n << " ";
    }
    cout << endl;

    l2.unique(); // 연속된 원소 중 중복된 원소를 제거

    for (auto n : l2) {
        cout << n << " ";
    }
    cout << endl;
}