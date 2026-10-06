#include <iostream>
using namespace std;

int main() {
    int q[5], front = -1, rear = -1, n = 5;

    cout << "Queue Capacity: 5" << endl;

    cout << "Join: 10" << endl;
    if ((rear + 1) % n != front) {
        if (front == -1) front = 0;
        rear = (rear + 1) % n;
        q[rear] = 10;
    }
    cout << "Front: " << q[front] << endl;

    cout << "Join: 20" << endl;
    if ((rear + 1) % n != front) {
        rear = (rear + 1) % n;
        q[rear] = 20;
    }
    cout << "Front: " << q[front] << endl;

    cout << "Join: 30" << endl;
    if ((rear + 1) % n != front) {
        rear = (rear + 1) % n;
        q[rear] = 30;
    }
    cout << "Front: " << q[front] << endl;

    cout << "Serve" << endl;
    if (front != -1) {
        cout << "Served: " << q[front] << endl;
        if (front == rear) front = rear = -1;
        else front = (front + 1) % n;
    }
    if (front != -1) cout << "Front: " << q[front] << endl;

    cout << "Join: 40" << endl;
    if ((rear + 1) % n != front) {
        if (front == -1) front = 0;
        rear = (rear + 1) % n;
        q[rear] = 40;
    }
    cout << "Front: " << q[front] << endl;

    return 0;
}