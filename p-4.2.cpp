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

    void deleteByValue(int token) {
        if (head == nullptr) {
            cout << "Patient not found: " << token << endl;
            return;
        }

        if (head->token == token) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr && temp->next->token != token) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Patient not found: " << token << endl;
            return;
        }

        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;
    }

    void forwardPrint() {
        cout << "Front to back: ";

        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->token << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void reversePrint(Node* temp) {
        if (temp == nullptr)
            return;

        reversePrint(temp->next);
        cout << temp->token << " ";
    }

    void reversePrint() {
        cout << "Back to front: ";
        reversePrint(head);
        cout << endl;
    }
};

int main() {
    PatientQueue p;

    p.addEnd(101);
    p.addEnd(102);
    p.addEnd(103);
    p.addFront(100);
    p.insertAt(105, 2);

    p.forwardPrint();

    p.deleteByValue(102);
    p.forwardPrint();

    p.reversePrint();

    return 0;
}
