#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
void print_queue(T pq) {
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

class Student{
public:
    string name;
    int score;

    bool operator < (const Student& st) const {
        return score < st.score;
    }
};

int main() {
    vector<int> vec {4, 2, 3, 5, 1};

    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2(vec.begin(), vec.end());

    for (auto e : vec) {
        pq1.push(e);
    }

    print_queue(pq1);
    print_queue(pq2);

    priority_queue<Student> students;
    students.push({"Amelia", 80});
    students.push({"Sophia", 40});
    students.push({"Olivia", 95});
    students.push({"George", 70});

    while (!students.empty()) {
        auto& s = students.top();
        cout << s.name << " is scored " << s.score << endl;
        students.pop();
    }
}