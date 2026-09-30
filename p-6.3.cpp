#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

string infixToPostfix(string exp) {
    stack<char> s;
    string result = "";

    for (char ch : exp) {

        if (ch == ' ')
            continue;

        if (isalnum(ch)) {
            result += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {

            while (!s.empty() && s.top() != '(') {
                result += s.top();
                s.pop();
            }

            if (!s.empty() && s.top() == '(')
                s.pop();
        }
        else {
            while (!s.empty() && priority(s.top()) >= priority(ch)) {
                result += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty()) {
        result += s.top();
        s.pop();
    }

    return result;
}

int main() {
    string exp;

    cout << "Enter infix expression: ";
    getline(cin, exp);

    cout << "Postfix expression: " << infixToPostfix(exp);

    return 0;
}