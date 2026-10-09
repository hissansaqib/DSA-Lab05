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
        if (head == nullptr){
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

    void PrintList (){
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

    void ClearList() {
        if(head == nullptr){
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
    
    cout << "Test empty list:" << endl;
    list.PrintList();
    cout << "Count: " << list.CountNodes() << endl;
    
    cout << "\nTest one node:" << endl;
    list.AddNode(10);
    list.PrintList();
    cout << "Count: " << list.CountNodes() << endl;
    list.ClearList();
    
    cout << "\nTest 10, 20, 30:" << endl;
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    list.PrintList();
    cout << "Count: " << list.CountNodes() << endl;
    
    cout << "\nExplanation:" << endl;
    cout << "In circular linked list, the last node points to the first node." << endl;
    cout << "So we cannot use nullptr to stop the loop." << endl;
    cout << "Hence we stop when we reach the head again." << endl;
    
    list.ClearList();
    return 0;
}