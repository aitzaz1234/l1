#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DList {
private:
    Node* head;
public:
    DList() {
        head = NULL;
    }

    bool emptyList() {
        return head == NULL;
    }

    void insert_after(int oldV, int newV) {
        Node* temp = head;
        while (temp != NULL && temp->data != oldV) {
            temp = temp->next;
        }
        if (temp != NULL) {
            Node* newNode = new Node(newV);
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }
    }

    void deleteNode(int value) {
        Node* temp = head;
        while (temp != NULL && temp->data != value) {
            temp = temp->next;
        }
        if (temp != NULL) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            }
            else {
                head = temp->next; // Deleting head node
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            delete temp;
        }
    }

    void insert_begin(int value) {
        Node* newNode = new Node(value);
        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    void insert_end(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void traverse() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DList list;
    list.insert_begin(3);
    list.insert_begin(2);
    list.insert_begin(1);
    list.insert_end(4);
    list.insert_after(2, 2);
    list.traverse();
    list.deleteNode(2);
    list.traverse();
    return 0;
}
