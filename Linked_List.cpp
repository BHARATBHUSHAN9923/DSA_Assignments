#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono; 


template<class T>
class LL{
    private:
        struct Node
    {
    T data;
    Node* next;
    Node(T value){
        data = value;
        next = NULL;
    }
    };
        Node *head;
    public: 
    LL(){
        head = NULL;
    }
    void insert(T x){
    if(head ==NULL) {head = new Node(x); return;}
    Node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node *temp2 = new Node(x);
    temp->next = temp2;
}
    void deleteNode(T x){
    if(head==NULL) return;
    Node *temp = head;
    if(head!=NULL && head->data == x){
        Node *temp = head->next;
        delete(head);
        head = temp;
        return;
    }
    else{
    while(temp->next!=NULL){
        if(temp->next->data==x) break;
        else temp = temp->next;
    }
    }
    Node *temp2 = temp->next->next;
    delete(temp->next);
    temp->next = temp2;
    return;
    
}
  bool SeekNode( T x){
    if(head==NULL) return false;
    Node *temp = head;
    while(temp!=NULL){
        if(temp->data==x) return true;
        temp = temp->next;
    }
    return false;
}
    void printlist(){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
};
vector<int> push_back_stl(){
    vector<int> stl_list_time;
    for(int i=10000; i<=100000; i+=500){
        //stl_list
        auto start = high_resolution_clock::now();
        list<int> stl_list;
        for(int j=1;j<=i;j++) stl_list.push_back(j);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<duration.count()<<" ";
        stl_list_time.push_back(duration.count());
    }
    return stl_list_time;
}
void compare_push_back(){

    vector<int> my_list_time, stl_list_time;
    for(int i=10000; i<=100000; i+=500){

        // my_list
        auto start = high_resolution_clock::now();
        LL<int> my_list;
        for(int j=1;j<=i;j++) my_list.insert(j);
        cout<<"running"<<endl;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"durtaion=="<<duration.count()<<" ";
        my_list_time.push_back(duration.count());
    }
    stl_list_time = push_back_stl();
    // cout << stl_list_time.size() << endl;
    std::ofstream myFile("compare_push_back.csv");
    myFile << "size, my_list, stl_list" << endl;
    for(int i=0; i<my_list_time.size();i++){
        myFile << 1000 + 100*i << ", " << my_list_time[i] << ", " << stl_list_time[i] << endl;
    }
}

int main(){
    compare_push_back();
    return 0;

}

//Circular Linked List
