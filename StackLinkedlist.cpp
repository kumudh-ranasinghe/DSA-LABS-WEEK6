#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <chrono>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void Push(Node*& top, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void Pop(Node*& top) {
    if (top == nullptr) {
        cout << "Stack Underflow" << endl;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

bool isEmpty(Node* top) {
    return top == nullptr;
}

int StackTop(Node* top) {
    if (top == nullptr) {
        cout << "Stack Underflow" << endl;
        return -1; 
    }
    return top->data;
}

void Display(Node* top) {
    cout << "Stack: ";
    while (top != nullptr) {
        cout << top->data << " ";
        top = top->next;
    }
    cout << endl;
}

int main() {

    double cpu_time_used;
    auto start = chrono::high_resolution_clock::now();

    Node* top = nullptr;

    Push(top,8);
    Push(top,10);
    Push(top,5);
    Push(top,11);
    Push(top,15);
    Push(top,23);
    Push(top,6);
    Push(top,18);
    Push(top,20);
    Push(top,17);
    Display(top);
    for(int i = 0; i < 5; i++){
        Pop(top);
    }
    Display(top);
    Push(top,4);
    Push(top,30);
    Push(top,3);
    Push(top,1);
    Display(top);

    auto end = chrono::high_resolution_clock::now();
    cpu_time_used = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Time taken: " << cpu_time_used << " microseconds" << endl;
    return 0;
}