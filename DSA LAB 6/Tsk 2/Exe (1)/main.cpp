#include <iostream>
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

void dectobin(int decimal) {
    Stack stack(32);

    while (decimal > 0) {
        int remainder = decimal % 2;
        stack.push(remainder);
        decimal /= 2;
    }

    cout << "Binary: ";
    while (!stack.isEmpty()) {
        cout << stack.pop();
    }
    cout << endl;
}

void dectooct(int decimal) {
    Stack stack(32);

    while (decimal > 0) {
        int remainder = decimal % 8;
        stack.push(remainder);
        decimal /= 8;
    }

    cout << "Octal: ";
    while (!stack.isEmpty()) {
        cout << stack.pop();
    }
    cout << endl;
}

int main() {
    int number;
    cout << "Enter a decimal number: ";
    cin >> number;

    dectobin(number);
    dectooct(number);

    return 0;
}
