#include <iostream>
using namespace std;

#define MAX_QUEUE 10

template <typename T>
class CircularQueue {
private:
    T* arr;
    int front_idx;
    int rear_idx;
    int count;
    int capacity;

public:
    CircularQueue(int sz = MAX_QUEUE) {
        arr = new T[sz];
        front_idx = 0;
        rear_idx = -1;
        count = 0;
        capacity = sz;
    }

    ~CircularQueue() {
        delete [] arr;
    }

    void enqueue(const T& e) {
        if (full()) {
            cout <<"Overflow error!" << endl;
            return; 
        }

        rear_idx = (rear_idx + 1) % capacity;
        arr[rear_idx] = e;
        count++;
    }

    void dequeue() {
        if (empty()) {
            cout << "Underflow error" << endl;
            return;
        }

        front_idx = (front_idx + 1) % capacity;
        count--;
    }

    const T& front() const {
        return arr[front_idx];
    }

    bool empty() {
        return count == 0;
    }

    int full() {
        return count == capacity;
    }

    int size() const {
        return count;
    }

};

int main() {
    CircularQueue<int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.dequeue();
    q.dequeue();

    q.enqueue(60);
    q.enqueue(70);

    q.dequeue();

    q.enqueue(80);
    
    while(!q.empty()) {
        cout << q.front() << " ";
        q.dequeue();
    }
}
