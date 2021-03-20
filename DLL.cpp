#include<bits/stdc++.h>
using namespace std;
template<class T>
class DLL{
    private:
    struct Node
    {   T data;
    Node *next;
    Node *prev;
    Node(T value){
        data = value;
        next = NULL;
        prev = NULL;
    }
    
    };
      Node *head;
    public:
    DLL(){
        head = NULL;
    }
    void insertAtend(T x){
    if(head ==NULL) {head = new Node(x); return;}
    Node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node *temp2 = new Node(x);
    temp ->next = temp2;
    temp2->prev = temp;
}
    void deleteNode(T x){
    if(head==NULL) return;
    Node *temp = head;
    if(head!=NULL && head->data ==x){
        Node *temp = head->next;
        delete(head);
        head = temp;
        return;
    }
    else{
        while(temp!=NULL){
            if(temp->data==x) break;
            else temp = temp->next;
        }
    }
    if(temp->next==NULL){
        Node *temp2= temp->prev;
        temp2->next = NULL;
        delete(temp);
        return;
    }
    Node *temp2 = temp->prev;
    temp2->next = temp->next;
    temp->next->prev = temp2;
    delete(temp);
}
    bool SeekNode(T x){
    if(head==NULL) return false;
    Node *temp = head;
    while(temp!=NULL){
        if(temp->data==x) return true;
        temp = temp->next;
    }
    return false;
}

void printList(){
    if(head==NULL) return;
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

};



int main(){
    DLL<char>dll;
    dll.insertAtend('a');
    dll.insertAtend('b');
    dll.insertAtend('c');
    dll.printList();
    dll.deleteNode('b');
    cout<<dll.SeekNode('a')<<endl;
    cout<<dll.SeekNode('c')<<endl;
    dll.printList();
    return 0;
}
