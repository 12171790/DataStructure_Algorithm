#include <iostream>
using namespace std;

int main() {
    int scores2[5]; // 초기화하지 않을 시 쓰레기 값이 들어가게 됨
    int scores1[5] = {}; // 모두 0으로 초기화됨
    int scores[5] = {50, 60, 70, 80, 90};

    int sz = sizeof(scores) / sizeof(int); // 배열의 크기 20 / 4
    int s = 0;
    for (int i = 0; i < sz; i++) {
        s += scores[i];
    }

    float m = (float) s / sz;

    cout << "Mean scroe : " << m << endl;
}