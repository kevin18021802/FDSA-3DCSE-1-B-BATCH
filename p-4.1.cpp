#include <iostream>
using namespace std;

class PatientQueue {
    int q[100];
    int n;

public:
    PatientQueue() {
        n = 0;
    }

    void addFront(int token) {
        for (int i = n; i > 0; i--) {
            q[i] = q[i - 1];
        }
        q[0] = token;
        n++;
    }

    void addEnd(int token) {
        q[n] = token;
        n++;
    }

    void insertAt(int token, int pos) {
        if (pos < 0 || pos > n) {
            cout << "Invalid position: " << pos << endl;
            return;
        }

        for (int i = n; i > pos; i--) {
            q[i] = q[i - 1];
        }

        q[pos] = token;
        n++;
    }

    void display() {
        cout << "Queue: ";
        for (int i = 0; i < n; i++) {
            cout << q[i] << " ";
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