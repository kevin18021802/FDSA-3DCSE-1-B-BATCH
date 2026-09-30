#include <iostream>
using namespace std;

class TrayStack {
    int *stack;
    int top;
    int capacity;

    public:
    TrayStack(int n) {
        capacity = n;
        stack = new int[capacity];
        top = -1;
    }

    void place(int tray) {
        if (top == capacity - 1) {
            cout << "Error: Stack is full. Cannot place tray " << tray << endl;
        } else {
            top++;
            stack[top] = tray;
            cout << "Placed tray: " << tray << endl;
        }

        displayTop();
    }

    void take() {
        if (top == -1) {
            cout << "Error: Stack is empty. Cannot take a tray." << endl;
        } else {
            cout << "Taken tray: " << stack[top] << endl;
            top--;
        }

        displayTop();
    }

    void displayTop() {
        if (top == -1)
            cout << "Top tray: None" << endl;
        else
            cout << "Top tray: " << stack[top] << endl;
    }

    ~TrayStack() {
        delete[] stack;
    }
};

int main() {
    int n, operations;

    cout << "Enter capacity: ";
    cin >> n;

    TrayStack s(n);

    cout << "Enter number of operations: ";
    cin >> operations;

    for (int i = 0; i < operations; i++) {
        string operation;
        cin >> operation;

        if (operation == "place") {
            int tray;
            cin >> tray;
            s.place(tray);
        }
        else if (operation == "take") {
            s.take();
        }
        else {
            cout << "Invalid operation" << endl;
        }
    }

    return 0;
}