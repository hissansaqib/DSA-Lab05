// Name: Muhammad Hissan Saqib
// Registration Number: 543530
// Section: BSCS-15-D

#include <iostream>
using namespace std;

class DoublyList{
private:
    struct node{
        int data;
        node* next;
        node* prev;
    };
    node* head;
    node* tail;

public:
    DoublyList(){
        head = nullptr;
        tail = nullptr;
    }

    void AddNode(int value){
        node* n = new node;
        n->data = value;
        n->next = nullptr;
        n->prev = nullptr;

        if(head == nullptr){
            head = n;
            tail = n;
        }
        else{
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void PrintForward(){
        if(head == nullptr){
            cout << "List is empty." << endl;
            return;
        }
        node* curr = head;
        while(curr != nullptr){
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }

    void PrintReverse(){
        if(tail == nullptr){
            cout << "List is empty." << endl;
            return;
        }
        node* curr = tail;
        while(curr != nullptr){
            cout << curr->data << " -> ";
            curr = curr->prev;
        }
        cout << "NULL" << endl;
    }

    void ClearList(){
        node* curr = head;
        while(curr != nullptr){
            node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
};

int main(){
    DoublyList list;

    cout << "Testing empty list:" << endl;
    list.PrintForward();
    list.PrintReverse();
    
    cout << "\nTesting one node:" << endl;
    list.AddNode(5);
    list.PrintForward();
    list.PrintReverse();
    list.ClearList();
    
    cout << "\nTesting 10, 20, 30:" << endl;
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    cout << "Forward output:" << endl;
    list.PrintForward();
    cout << "Reverse output:" << endl;
    list.PrintReverse();
    list.ClearList();

    int count;
    cout << "\nEnter a non-negative count to append integers: ";
    cin >> count;
    for(int i = 0; i < count; i++){
        int val;
        cout << "Enter value " << i+1 << ": ";
        cin >> val;
        list.AddNode(val);
    }
    
    cout << "Forward output:" << endl;
    list.PrintForward();
    cout << "Reverse output:" << endl;
    list.PrintReverse();

    list.ClearList();
    return 0;
}