#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Stack {
private:
    char* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new char[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(char value) {
        if (top < capacity - 1) {
            arr[++top] = value;
        } else {
            cout << "Stack overflow\n";
        }
    }

    char pop() {
        if (top >= 0) {
            return arr[top--];
        } else {
            cout << "Stack underflow\n";
            return '\0';
        }
    }

    char peek() const {
        if (top >= 0) {
            return arr[top];
        } else {
            return '\0';
        }
    }

    bool isEmpty() const {
        return top == -1;
    }
};

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool checkParentheses(const string& expression) {
    Stack stack(expression.length());

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.isEmpty() || !isMatchingPair(stack.pop(), ch)) {
                return false;
            }
        }
    }

    return stack.isEmpty();
}

void validateExpression(const string& inputFile) {
    ifstream inFile(inputFile);

    if (!inFile) {
        cout << "Error opening file.\n";
        return;
    }

    string expression;
    getline(inFile, expression);

    if (checkParentheses(expression)) {
        cout << "The parentheses are balanced.\n";
    } else {
        cout << "The parentheses are not balanced.\n";
    }

    inFile.close();
}

int main() {
    string inputFile = "expression.txt";

    validateExpression(inputFile);

    return 0;
}
