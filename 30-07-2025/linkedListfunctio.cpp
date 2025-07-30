#include<iostream>
using namespace std;
class node {
public:
    int value;
    node* next;

    node(int val) {
        value = val;
        next = nullptr;
    }
};

class MyLinkedList {
    node* head;

public:
    MyLinkedList() {
        head = nullptr;
    }

    int get(int index) {
        node* tp = head;
        for (int i = 0; i < index && tp != nullptr; i++) {
            tp = tp->next;
        }
        return (tp != nullptr) ? tp->value : -1;
    }

    void addAtHead(int val) {
        node* newnode = new node(val);
        newnode->next = head;
        head = newnode;
    }

    void addAtTail(int val) {
        node* newnode = new node(val);
        if (head == nullptr) {
            head = newnode;
            return;
        }
        node* tp = head;
        for (; tp->next != nullptr; tp = tp->next);
        tp->next = newnode;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        node* tp = head;
        for (int i = 0; i < index - 1 && tp != nullptr; i++) {
            tp = tp->next;
        }

        if (tp == nullptr) return;  // index out of bounds

        node* newnode = new node(val);
        newnode->next = tp->next;
        tp->next = newnode;
    }

    void deleteAtIndex(int index) {
        if (index == 0 && head != nullptr) {
            node* del = head;
            head = head->next;
            delete del;
            return;
        }

        node* tp = head;
        for (int i = 0; i < index - 1 && tp != nullptr; i++) {
            tp = tp->next;
        }

        if (tp == nullptr || tp->next == nullptr) return;

        node* del = tp->next;
        tp->next = del->next;
        delete del;
    }
    void printList() {
        node* tp = head;
        while (tp != nullptr) {
            cout << tp->value << " ";
            tp = tp->next;
        }
        cout << endl;
    }
};
int main() {
    MyLinkedList linkedList;
    linkedList.addAtHead(1);
    linkedList.addAtTail(2);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1, 4); 
    linkedList.printList();  // List becomes 1->4->2->3
    cout << linkedList.get(1) << endl;  // Returns 4
    linkedList.addAtHead(5);  // List becomes 5->1->4->2->3
    linkedList.printList();
    linkedList.deleteAtIndex(2);  // List becomes 1->4->3
    linkedList.printList();
    cout << linkedList.get(2) << endl;  // Returns 3
    return 0;
}