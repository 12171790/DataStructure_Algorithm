#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2(10);    // 10개의 공간이 모두 0으로 초기화 되어있음.
    vector<int> v3(10, 1); // 10개의 공간이 모두 1로 초기화 되어있음.
    vector<int> v4{10, 20, 30, 40, 50};
    vector<int> v5 = v4;                        // v5는 v4를 깊은 복사 (데이터 자체를 통째로 복사하여 완전히 독립적인 메모리를 차지)
    vector<int> v6(v4.begin(), v4.begin() + 3); // v4의 처음부터 3개의 원소를 v6에 복사

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);

    for (int i = 0; i < v6.size(); i++)
    {
        cout << v6[i] << endl;
    }

    // 2차원 벡터 생성
    vector<vector<int>> mat1(2, vector<int>(3));    // 2행 3열 2차원 벡터를 모두 0으로 초기화
    vector<vector<int>> mat2(2, vector<int>(3, 1)); // 2행 3열 2차원 벡터를 모두 1로 초기화

    vector<vector<int>> mat3 {{1, 2, 3}, {4, 5, 6}};

    for (int i = 0; i < mat3.size(); i++) {
        for (int j = 0; j < mat3[i].size(); j++) {
            cout << mat3[i][j] << " ";
        }
        cout << endl;
    }
}