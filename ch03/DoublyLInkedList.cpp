#include <iostream>
using namespace std;
class Node {
public:
    Node(int val, Node* p1, Node* p2) : data(val), prev(p1), next(p2) {} 

    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    int count; // 현재 연결 리스트에 들어있는 노드의 개수
    Node* header;
    Node* trailer;

public:
    DoublyLinkedList() : count(0) {
        header = new Node(0, nullptr, nullptr);
        trailer = new Node(0, nullptr, nullptr);
        header->next = trailer;
        trailer->prev = header;
    }
    ~DoublyLinkedList() {
        while(!empty()) {
            pop_front();
        }

        delete header;
        delete trailer;
    }

    void insert(Node* p, int val) {
        Node* new_node = new Node(val, p->prev, p);
        p->prev->next = new_node;
        p->prev = new_node;
        count++;
    }

    void push_front(int val) {
        insert(header->next, val);
    }

    void push_back(int val) {
        insert(trailer, val);
    }

    void erase(Node* p) {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        count--;
    }

    void pop_front() {
        if(!empty()) {
            erase(header->next);
        }
    }

    void pop_back() {
        if(!empty()) {
            erase(trailer->prev);
        }
    }

    void print_all() {
        Node* curr = header->next;

        while(curr != trailer) {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }
    void print_reverse() {
        Node* curr = trailer->prev;

        while(curr != header) {
            cout << curr->data << " ";
            curr = curr->prev;
        }

        cout << endl;
    }

    bool empty() {
        return count == 0;
    }

    int size() {
        return count;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.push_front(10);
    dll.push_front(20);
    dll.push_front(10);
    dll.push_back(50);
    dll.push_back(50);
    dll.push_back(40);

    dll.print_all();
    dll.print_reverse();

    dll.pop_front();
    dll.pop_back();

    dll.print_all();
}