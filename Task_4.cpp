// Name: Muhammad Hissan Saqib
// Registration Number: 543530
// Section: BSCS-15-D

#include <iostream>
using namespace std;

class CircularList{
private:
    struct node{
        int data;
        node* next;
    };
    node* head;
    node* tail;

public:
    CircularList(){
        head = nullptr;
        tail = nullptr;
    }

    void AddNode(int value){
        node* n = new node;
        n->data = value;
        if(head == nullptr){
            head = n;
            tail = n;
            n->next = head;
        }
        else{
            tail->next = n;
            tail = n;
            tail->next = head;
        }
    }

    void DeleteNode(int value){
        if(head == nullptr) return;
        
        node* curr = head;
        node* prev = tail;
        
        do{
            if(curr->data == value){
                if(curr == head && curr == tail){
                    delete curr;
                    head = nullptr;
                    tail = nullptr;
                }
                else if(curr == head){
                    head = curr->next;
                    tail->next = head;
                    delete curr;
                }
                else if(curr == tail){
                    tail = prev;
                    tail->next = head;
                    delete curr;
                }
                else{
                    prev->next = curr->next;
                    delete curr;
                }
                return; 
            }
            prev = curr;
            curr = curr->next;
        }while(curr != head);
    }

    void PrintList(){
        if(head == nullptr){
            cout << "List is empty." << endl;
            return;
        }
        node* curr = head;
        do{
            cout << curr->data << " -> ";
            curr = curr->next;
        }while(curr != head);
        cout << "(head)" << endl;
    }

    int CountNodes(){
        if(head == nullptr){
            return 0;
        }
        int count = 0;
        node* curr = head;
        do{
            count++;
            curr = curr->next;
        }while(curr != head);
        return count;
    }

    void ClearList(){
        if(head == nullptr) {
            return;
        }
        tail->next = nullptr;
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
    CircularList list;
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    cout << "Initial list:" << endl;
    list.PrintList();

    cout << "\nDeleting 10:" << endl;
    list.DeleteNode(10);
    list.PrintList();
    cout << "Count: " << list.CountNodes() << endl;
    
    cout << "\nDeleting 30:" << endl;
    list.DeleteNode(30);
    list.PrintList();
    cout << "Count: " << list.CountNodes() << endl;
    
    cout << "\nDeleting 20:" << endl;
    list.DeleteNode(20);
    list.PrintList();
    cout << "Count: " << list.CountNodes() << endl;
    
    cout << "\nTest empty list deletion:" << endl;
    list.DeleteNode(99);
    list.PrintList();
    
    cout << "\nTest missing value:" << endl;
    list.AddNode(10);
    list.DeleteNode(99);
    list.PrintList();
    list.ClearList();
    
    cout << "\nTest duplicates (deleting 20 once from 10, 20, 20, 30):" << endl;
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(20);
    list.AddNode(30);
    list.DeleteNode(20);
    list.PrintList();
    cout << "Count: " << list.CountNodes() << endl;
    list.ClearList();
    return 0;
}