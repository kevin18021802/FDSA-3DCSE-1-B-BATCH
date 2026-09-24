#include <iostream>
using namespace std;

struct Node {
    int student;
    Node* next;

    Node(int x) {
        student = x;
        next = NULL;
    }
};

class CircularList {
    Node* last;

public:
    CircularList() {
        last = NULL;
    }

    void join(int student) {
        Node* newNode = new Node(student);

        if (last == NULL) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    void leave(int student) {
        if (last == NULL)
            return;

        Node* current = last->next;
        Node* previous = last;

        do {
            if (current->student == student) {
                if (current == last && current->next == last) {
                    delete current;
                    last = NULL;
                    return;
                }

                previous->next = current->next;

                if (current == last)
                    last = previous;

                delete current;
                return;
            }

            previous = current;
            current = current->next;

        } while (current != last->next);
    }

    void display() {
        if (last == NULL) {
            cout << "Circle is empty\n";
            return;
        }

        Node* current = last->next;

        do {
            cout << current->student << " ";
            current = current->next;
        } while (current != last->next);

        cout << endl;
    }
};

int main() {
    CircularList circle;

    int choice, student;

    do {
        cout << "\n1. Join";
        cout << "\n2. Leave";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter student number: ";
                cin >> student;
                circle.join(student);
                break;

            case 2:
                cout << "Enter student number: ";
                cin >> student;
                circle.leave(student);
                break;

            case 3:
                circle.display();
                break;

            case 4:
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}