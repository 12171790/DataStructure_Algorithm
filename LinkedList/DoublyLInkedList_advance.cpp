#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    Node(int val, Node *p1, Node *p2) : data(val), prev(p1), next(p2) {}

    T data;
    Node *prev;
    Node *next;
};

template <typename T>
class DoublyLinkedList
{
private:
    int count; // 현재 연결 리스트에 들어있는 노드의 개수
    Node<T> *header;
    Node<T> *trailer;

public:
    class iterator
    {
    private:
        Node<T> *ptr;

    public:
        iterator() : ptr(nullptr) {}
        iterator(Node<T> *p) : ptr(p) {}

        T &operator*() { return ptr->data; }

        iterator &operator++()
        {
            ptr = ptr->next;
            return *this;
        }

        iterator &operator--()
        {
            ptr = ptr->prev;
            return *this;
        }

        bool operator==(const iterator &it) const
        {
            return ptr == it.ptr;
        }

        bool operator!=(const iterator &it) const
        {
            return ptr != it.ptr;
        }

        // DoublyLinkedList에서 iterator 내부의 ptr에 접근 가능
        friend class DoublyLinkedList;
    };

    DoublyLinkedList() : count(0)
    {
        header = new Node<T>(T(), nullptr, nullptr);
        trailer = new Node<T>(T(), nullptr, nullptr);
        header->next = trailer;
        trailer->prev = header;
    }
    ~DoublyLinkedList()
    {
        while (!empty())
        {
            pop_front();
        }

        delete header;
        delete trailer;
    }

    iterator begin() const
    {
        return iterator(header->next);
    }

    iterator end() const {
        return iterator(trailer);
    }

    void insert(const iterator& pos, const T& val)
    {
        Node<T>* p = pos.ptr;
        Node<T> *new_node = new Node<T>(val, p->prev, p);
        p->prev->next = new_node;
        p->prev = new_node;
        count++;
    }

    void push_front(const T& val)
    {
        insert(begin(), val);
    }

    void push_back(const T& val)
    {
        insert(end(), val);
    }

    void erase(const iterator& pos)
    {
        Node<T>* p = pos.ptr;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        count--;
    }

    void pop_front()
    {
        if (!empty())
        {
            erase(begin());
        }
    }

    void pop_back()
    {
        if (!empty())
        {
            erase(--end());
        }
    }

    void print_all()
    {
        Node<T> *curr = header->next;

        while (curr != trailer)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }
    void print_reverse()
    {
        Node<T> *curr = trailer->prev;

        while (curr != header)
        {
            cout << curr->data << " ";
            curr = curr->prev;
        }

        cout << endl;
    }

    bool empty()
    {
        return count == 0;
    }

    int size()
    {
        return count;
    }

    iterator find(const T& val) {
        Node<T>* curr = header->next;

        while(curr->data != val && curr != trailer) {
            curr = curr->next;
        }

        return iterator(curr);
    }
};

int main()
{
    DoublyLinkedList<int> dll;
    dll.push_front(10);
    dll.push_front(20);
    dll.push_front(10);
    dll.push_back(50);
    dll.push_back(50);
    dll.push_back(40);

    auto it = dll.find(20);
    if (it != dll.end()) {
        dll.insert(it, 100);
    }

    for (auto n : dll) {
        cout << n << " ";
    }
    cout << endl;
}