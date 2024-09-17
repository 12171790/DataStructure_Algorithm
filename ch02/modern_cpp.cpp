#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> odds()
{
    return {1, 3, 5, 7, 9};
}

template <typename T>
using matrix1d = vector<T>;

void my_function(int n) {
    cout << "Function called" << endl;
}

int main()
{

    auto a1 = 10;         // int
    auto a2 = 3.14f;      // float
    auto a3 = "hello";    // const char*
    auto a4 = "hello"s;   // string
    auto a5 = sqrt(2.0);  // double
    auto a6 = odds();     // vector<int>
    auto a7 = a6.begin(); // vector<int>::iterator
    auto lambda = [](int x)
    { return x * 2; };

    // 타입 정의 (aliasing)
    using uchar = unsigned char;
    using pis = pair<int, string>;
    using da10 = double[10];
    using func = void(*)(int);

    da10 arr {};
    matrix1d<float> vec(3);
    func fp = &my_function;

    // 범위 기반 for 문
    vector<int> numbers {10, 20, 30};

    // n을 얕은 복사로 불러옴.
    for (int n : numbers) {
        cout << n << endl;
    }

    // n을 참조 형태로 받아옴.
    // n 값을 변경할 시 numbers의 값도 변경됨.
    for (auto& n : numbers) {
        cout << n << endl;
    }

    string strs[] = {"I", "love", "you"};
    // 참조 형태로 받아온 값을 수정하지 않음을 의미.
    for (const auto& s : strs) {
        cout << s << " ";
    }

    // 람다 표현식
    auto square = [](double a) {return a * a;};
    cout << "square(1.414) = " << square(1.414) << endl;

}