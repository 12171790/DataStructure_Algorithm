#include <iostream>
#include <list>
using namespace std;

template <typename T>
class Queue{
private:
    list<T> list;

public:
    Queue() {}

    void enqueue(const T& e) {
        list.push_back(e);
    }

    void dequeue() {
        list.pop_front();
    }

    const T& front() const {
        list.front();
    }

    bool empty() const {
        return list.empty();
    }

    int size() const {
        return list.size();
    }
};

int main() {
    Queue<int> qu;

    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);

    cout << qu.front() << endl;

    qu.dequeue();

    cout << qu.front() << endl;

    qu.enqueue(40);

    while(!qu.empty()) {
        cout << qu.front() << " ";
        qu.dequeue();
    }
    cout << endl;
}