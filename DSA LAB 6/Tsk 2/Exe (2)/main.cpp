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

    bool isEmpty() const {
        return top == -1;
    }
};

void reverseString(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile || !outFile) {
        cout << "Error opening file.\n";
        return;
    }

    string line;
    getline(inFile, line);

    Stack stack(line.length());

    for (char ch : line) {
        stack.push(ch);
    }

    string reversedString;
    while (!stack.isEmpty()) {
        reversedString += stack.pop();
    }

    outFile << reversedString;

    inFile.close();
    outFile.close();
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "output.txt";

    reverseString(inputFile, outputFile);

    cout << "String reversed and written to " << outputFile << endl;

    return 0;
}
