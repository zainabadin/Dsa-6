#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (top < capacity - 1) {
            arr[++top] = value;
        } else {
            cout << "Stack overflow\n";
        }
    }

    int pop() {
        if (top >= 0) {
            return arr[top--];
        } else {
            cout << "Stack underflow\n";
            return -1;
        }
    }

    bool isEmpty() const {
        return top == -1;
    }
};

int evaluatePostfix(const string& expression) {
    Stack stack(expression.length());

    for (char ch : expression) {
        if (isdigit(ch)) {
            stack.push(ch - '0');
        } else {
            int operand2 = stack.pop();
            int operand1 = stack.pop();

            switch (ch) {
                case '+': stack.push(operand1 + operand2); break;
                case '-': stack.push(operand1 - operand2); break;
                case '*': stack.push(operand1 * operand2); break;
                case '/': 
                    if (operand2 != 0) stack.push(operand1 / operand2); 
                    else {
                        cout << "Error: Division by zero\n";
                        return -1;
                    }
                    break;
                default:
                    cout << "Error: Unknown operator " << ch << endl;
                    return -1;
            }
        }
    }

    return stack.pop();
}

void evaluateExpressionFromFile(const string& inputFile) {
    ifstream inFile(inputFile);

    if (!inFile) {
        cout << "Error opening file.\n";
        return;
    }

    string expression;
    getline(inFile, expression);

    int result = evaluatePostfix(expression);
    cout << "The result of the postfix expression is: " << result << endl;

    inFile.close();
}

int main() {
    string inputFile = "postfix_expression.txt";
    evaluateExpressionFromFile(inputFile);

    return 0;
}
