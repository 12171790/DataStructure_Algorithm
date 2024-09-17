#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {};
    Node(int val, Node* n) : data(val), next(n) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(NULL) {}
    ~LinkedList() {
        while(!empty()) {
            pop_front();
        }
    }

    void push_front(int val) {
        Node* new_node = new Node(val, NULL);
        
        if (head != NULL) {
            new_node->next = head; 
        }
        head = new_node;
    }
    void pop_front() {
        if (head == NULL) {
            return;
        }

        Node* temp_node = head;
        head = head->next;

        delete temp_node;
    };

    void print_all() {
        Node* print = head;

        while(print != NULL) {
            cout << print->data << " ";
            print = print->next;
        }
        cout << endl;
    };

    bool empty() {
        return head == NULL;
    };

};

int main() {
    LinkedList ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.push_front(40);

    ll.print_all();
    
    ll.pop_front();
    ll.pop_front();

    ll.print_all();

    cout << ll.empty() << endl;

    ll.pop_front();
    ll.pop_front();

    cout << ll.empty() << endl;

    // main 함수가 끝나면 ll의 소멸자가 자동 호출
}