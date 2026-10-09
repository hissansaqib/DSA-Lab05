// Name: Muhammad Hissan Saqib
// Registration Number: 543530
// Section: BSCS-15-D

#include <iostream>
using namespace std;

class LinkedStack{
private:
    struct node{
        int data;
        node* next;
    };
    node* top;
public:
    LinkedStack(){
        top = nullptr;
    }
    
    bool IsEmpty(){
        return top == nullptr;
    }
    
    void Push(int value){
        node* n = new node;
        n->data = value;
        n->next = top;
        top = n;
    }
    
    void Pop(){
        if(IsEmpty()){
            cout << "Stack underflow. Cannot pop." << endl;
            return;
        }
        node* temp = top;
        cout << "Popped: " << temp->data << endl;
        top = top->next;
        delete temp;
    }
    
    void Peek(){
        if(IsEmpty()){
            cout << "Stack underflow. Cannot peek." << endl;
            return;
        }
        cout << "Top element is: " << top->data << endl;
    }
    
    void Display(){
        if(IsEmpty()){
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack from top to bottom:" << endl;
        node* curr = top;
        while(curr != nullptr){
            cout << curr->data << endl;
            curr = curr->next;
        }
    }
    
    void ClearStack(){
        while(!IsEmpty()){
            node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main(){
    LinkedStack stack;
    int choice;
    int val;
    
    while(true){
        cout << "\n--- Linked Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Run Required Test Sequence" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice == 1){
            cout << "Enter value to push: ";
            cin >> val;
            stack.Push(val);
        }
        else if(choice == 2){
            stack.Pop();
        }
        else if(choice == 3){
            stack.Peek();
        }
        else if(choice == 4){
            stack.Display();
        }
        else if(choice == 5){
            stack.ClearStack();
            
            stack.Push(10);
            stack.Push(20);
            stack.Push(30);
            
            cout << "\nDisplaying stack:" << endl;
            stack.Display();
            
            cout << "\nTesting Pop and Peek:" << endl;
            stack.Pop(); 
            stack.Peek(); 
            
            cout << "\nTesting deletion until empty and one further pop:" << endl;
            stack.Pop();
            stack.Pop();
            stack.Pop(); 
            
            stack.Push(99);
            stack.Push(100);
            cout << "\nNodes remaining in stack to test ClearStack on exit." << endl;
        }
        else if (choice == 6){
            cout << "Exiting menu. Clearing remaining nodes in stack..." << endl;
            stack.ClearStack();
            
            cout << "\nExplanation:" << endl;
            cout << "LIFO means the last element added to the stack is the first one removed." << endl;
            cout << "An Array Stack has a fixed size, so it can become full." << endl;
            cout << "A Linked Stack grows dynamically by using pointers, so it can grow as needed." << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    
    return 0;
}