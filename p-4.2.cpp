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

    void deleteByValue(int token) {
        int pos = -1;

        for (int i = 0; i < n; i++) {
            if (q[i] == token) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            cout << "Patient not found: " << token << endl;
            return;
        }

        for (int i = pos; i < n - 1; i++) {
            q[i] = q[i + 1];
        }

        n--;
    }

    void forwardPrint() {
        cout << "Front to back: ";
        for (int i = 0; i < n; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }

    void reversePrint() {
        cout << "Back to front: ";
        for (int i = n - 1; i >= 0; i--) {
            cout << q[i] << " ";
        }
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