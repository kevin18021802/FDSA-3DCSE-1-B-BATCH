#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = NULL;
        next = NULL;
    }
};

class Playlist {
    Node* head;
    Node* tail;
    Node* current;

public:
    Playlist() {
        head = NULL;
        tail = NULL;
        current = NULL;
    }

    void addBeginning(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = current = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addEnd(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = current = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void addAfterCurrent(string song) {
        if (current == NULL) {
            addBeginning(song);
            return;
        }

        Node* newNode = new Node(song);

        newNode->prev = current;
        newNode->next = current->next;

        if (current->next != NULL)
            current->next->prev = newNode;
        else
            tail = newNode;

        current->next = newNode;
    }

    void removeSong(string song) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->song == song) {
                if (temp->prev != NULL)
                    temp->prev->next = temp->next;
                else
                    head = temp->next;

                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
                else
                    tail = temp->prev;

                if (current == temp)
                    current = temp->next ? temp->next : head;

                delete temp;
                return;
            }

            temp = temp->next;
        }
    }

    int countSongs() {
        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void display() {
        Node* temp = head;

        if (temp == NULL) {
            cout << "Playlist is empty\n";
            return;
        }

        while (temp != NULL) {
            cout << temp->song;
            if (temp == current)
                cout << " [Playing]";

            cout << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    void setCurrent(string song) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->song == song) {
                current = temp;
                return;
            }
            temp = temp->next;
        }

        cout << "Song not found\n";
    }
};

int main() {
    Playlist p;
    int choice;
    string song;

    do {
        cout << "\n1. Add at beginning";
        cout << "\n2. Add at end";
        cout << "\n3. Add after current";
        cout << "\n4. Remove song";
        cout << "\n5. Set current song";
        cout << "\n6. Count songs";
        cout << "\n7. Display";
        cout << "\n8. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter song: ";
                cin >> song;
                p.addBeginning(song);
                break;

            case 2:
                cout << "Enter song: ";
                cin >> song;
                p.addEnd(song);
                break;

            case 3:
                cout << "Enter song: ";
                cin >> song;
                p.addAfterCurrent(song);
                break;

            case 4:
                cout << "Enter song to remove: ";
                cin >> song;
                p.removeSong(song);
                break;

            case 5:
                cout << "Enter current song: ";
                cin >> song;
                p.setCurrent(song);
                break;

            case 6:
                cout << "Number of songs: " << p.countSongs() << endl;
                break;

            case 7:
                p.display();
                break;

            case 8:
                cout << "Program ended\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 8);

    return 0;
}