#include <iostream>
#include <vector>
using namespace std;

class Browser {
    vector<string> history;
    int current;

public:
    Browser(string firstPage) {
        history.push_back(firstPage);
        current = 0;
    }

    void visit(string page) {
        history.push_back(page);
        current++;

        cout << "Visited: " << page << endl;
        cout << "Current page: " << history[current] << endl;
    }

    void back() {
        if (current == 0) {
            cout << "Error: No previous page available." << endl;
        } 
        else {
            current--;
            cout << "Back to: " << history[current] << endl;
        }

        cout << "Current page: " << history[current] << endl;
    }
};

int main() {
    string firstPage;
    int n;

    cout << "Enter first page: ";
    cin >> firstPage;

    Browser browser(firstPage);

    cout << "Enter number of operations: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;

        if (operation == "visit") {
            string page;
            cin >> page;
            browser.visit(page);
        }
        else if (operation == "back") {
            browser.back();
        }
    }

    return 0;
}