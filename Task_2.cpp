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

    void InsertBefore(int position, int value){
        if(position < 1 || head == nullptr){
            return; 
        }
        if(position == 1){
            node* n = new node;
            n->data = value;
            n->prev = nullptr;
            n->next = head;
            head->prev = n;
            head = n;
            return;
        }
        
        node* curr = head;
        int currentPos = 1;
        while(curr != nullptr && currentPos < position){
            curr = curr->next;
            currentPos++;
        }
        
        if(curr == nullptr){
            return; 
        }
        
        node* n = new node;
        n->data = value;
        n->next = curr;
        n->prev = curr->prev;
        curr->prev->next = n;
        curr->prev = n;
    }

    void DeleteNode(int value){
        node* curr = head;
        while(curr != nullptr){
            if(curr->data == value){
                if(curr == head && curr == tail){
                    head = nullptr;
                    tail = nullptr;
                }
                else if(curr == head){
                    head = curr->next;
                    head->prev = nullptr;
                }
                else if(curr == tail){
                    tail = curr->prev;
                    tail->next = nullptr;
                }
                else{
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                }
                delete curr;
                return;
            }
            curr = curr->next;
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

    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    cout << "Original list:" << endl;
    list.PrintForward();
    
    list.InsertBefore(2, 15);
    list.DeleteNode(20);
    cout << "\nAfter inserting 15 before position 2 and deleting 20:" << endl;
    list.PrintForward();
    list.PrintReverse();
    
    cout << "\nTest insertion before head:" << endl;
    list.InsertBefore(1, 5);
    list.PrintForward();
    list.PrintReverse();
    
    cout << "\nTest deletion of head:" << endl;
    list.DeleteNode(5);
    list.PrintForward();
    list.PrintReverse();
    
    cout << "\nTest deletion of tail:" << endl;
    list.DeleteNode(30);
    list.PrintForward();
    list.PrintReverse();
    
    cout << "\nTest a missing value:" << endl;
    list.DeleteNode(99);
    list.PrintForward();
    list.PrintReverse();
    
    list.ClearList();
    
    cout << "\nTest the only node:" << endl;
    list.AddNode(42);
    list.PrintForward();
    list.DeleteNode(42);
    cout << "After deletion:" << endl;
    list.PrintForward();
    list.PrintReverse();
    
    cout << "\nTest empty list:" << endl;
    list.DeleteNode(10);
    list.PrintForward();

    return 0;
}