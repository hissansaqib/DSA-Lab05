// Name: Muhammad Hissan Saqib
// Registration Number: 543530
// Section: BSCS-15-D

#include <iostream>
using namespace std;

class ArrayStack{
private:
    int items[5];
    int top;
public:
    ArrayStack(){
        top = -1;
    }
    
    bool IsEmpty(){
        return top == -1;
    }
    
    bool IsFull(){
        return top == 4;
    }
    
    void Push(int value){
        if(IsFull()){
            cout << "Stack overflow. Cannot push " << value << endl;
            return;
        }
        top++;
        items[top] = value;
    }
    
    void Pop(){
        if(IsEmpty()){
            cout << "Stack underflow. Cannot pop." << endl;
            return;
        }
        cout << "Popped: " << items[top] << endl;
        top--;
    }
    
    void Peek(){
        if(IsEmpty()){
            cout << "Stack underflow. Cannot peek." << endl;
            return;
        }
        cout << "Top element is: " << items[top] << endl;
    }
    
    void Display(){
        if(IsEmpty()){
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack from top to bottom:" << endl;
        for(int i = top; i >= 0; i--){
            cout << items[i] << endl;
        }
    }
};

int main(){
    ArrayStack stack;
    
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);
    
    cout << "\nTrying to push a 6th value:" << endl;
    stack.Push(60); 
    
    cout << "\nPopping top element:" << endl;
    stack.Pop(); 
    
    cout << "\nPeeking at new top:" << endl;
    stack.Peek(); 
    
    cout << "\nEmptying the stack:" << endl;
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();
    
    cout << "\nTesting one further pop:" << endl;
    stack.Pop(); 
    
    return 0;
}