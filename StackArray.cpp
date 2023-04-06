#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <chrono>

using namespace std;

const int MaxSize = 100;
int S[MaxSize];
int top = -1;

void Push(int x){
    if(top >= MaxSize-1){
        cout << "Stack Overflow" << endl;
    }else{
        top++;
        S[top] = x;
    }
}

void Pop(){
    if(top <=-1){
        cout << "Stack Underflow" << endl;
    }else{
        top--;
    }
}

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MaxSize - 1;
}

int StackTop() {
    if (top == -1) {
        std::cout << "Error: Stack is empty\n";
        return -1;
    } else {
        return S[top];
    }
}

void Display() {
    cout << "Stack: ";
    for (int i = 0; i <= top; i++) {
        cout << S[i] << " ";
    }
    cout << endl;
}

int main() {

    double cpu_time_used;
    auto start = chrono::high_resolution_clock::now();

    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);
    Display();
    for(int i = 0; i < 5; i++){
        Pop();
    }
    Display();
    Push(4);
    Push(30);
    Push(3);
    Push(1);
    Display();

    auto end = chrono::high_resolution_clock::now();
    cpu_time_used = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Time taken: " << cpu_time_used << " microseconds" << endl;
    return 0;
}