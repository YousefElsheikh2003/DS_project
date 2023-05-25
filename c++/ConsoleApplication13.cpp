#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
    int size;
    char* stackArr;
    int top;

public:
    Stack(int stackSize) {
        size = stackSize;
        stackArr = new char[size];
        top = -1;
    }

    ~Stack() {
        delete[] stackArr;
    }

    void push(char value) {
        if (isFull()) {
            cout << "Stack is full!" << endl;
        }
        else {
            top++;
            stackArr[top] = value;
        }
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return '\0';
        }
        else {
            char poppedValue = stackArr[top];
            top--;
            return poppedValue;
        }
    }

    char peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return '\0';
        }
        else {
            return stackArr[top];
        }
    }

    bool isFull() {
        return top == size - 1;
    }

    bool isEmpty() {
        return top == -1;
    }
};

string InfixToPostfix(string expression);
string PostfixToInfix(string expression);

int main() {
    int choice;
    string expression, result;

    cout << "Choose an option:\n";
    cout << "1. Convert Infix to Postfix\n";
    cout << "2. Convert Postfix to Infix\n";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Enter Infix Expression: ";
        cin >> expression;
        result = InfixToPostfix(expression);
        cout << "Postfix Expression: " << result << endl;
        break;
    case 2:
        cout << "Enter Postfix Expression: ";
        cin >> expression;
        result = PostfixToInfix(expression);
        cout << "Infix Expression: " << result << endl;
        break;
    default:
        cout << "Invalid choice\n";
        break;
    }

    return 0;
}

string InfixToPostfix(string expression) {
    Stack s(expression.length());
    string result;

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        if (isalpha(ch) || isdigit(ch)) {
            result += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                result += s.pop();
            }

            if (!s.isEmpty() && s.peek() == '(') {
                s.pop();
            }
            else {
                cout << "Invalid Expression\n";
                return "";
            }
        }
        else {
            while (!s.isEmpty() && s.peek() != '(' && ((ch == '*' || ch == '/') || (ch == '+' || ch == '-'))) {
                result += s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.isEmpty()) {
        result += s.pop();
    }

    return result;
}

string PostfixToInfix(string expression) {
    Stack;

