#include <iostream>
using namespace std;

class PatientQueue {
    struct Node {
        int token;
        Node* next;

        Node(int t) {
            token = t;
            next = nullptr;
        }
    };

    Node* head;

public:
    PatientQueue() {
        head = nullptr;
    }

    void addFront(int token) {
        Node* newNode = new Node(token);

        newNode->next = head;
        head = newNode;
    }

    void addEnd(int token) {
        Node* newNode = new Node(token);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insertAt(int token, int pos) {
        if (pos < 0) {
            cout << "Invalid position: " << pos << endl;
            return;
        }

        if (pos == 0) {
            addFront(token);
            return;
        }

        Node* temp = head;

        for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position: " << pos << endl;
            return;
        }

        Node* newNode = new Node(token);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display() {
        cout << "Queue: ";

        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->token << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    PatientQueue p;

    p.addEnd(101);
    p.display();

    p.addEnd(102);
    p.display();

    p.addFront(99);
    p.display();

    p.insertAt(100, 1);
    p.display();

    p.insertAt(105, 10);
    p.display();

    return 0;
}
