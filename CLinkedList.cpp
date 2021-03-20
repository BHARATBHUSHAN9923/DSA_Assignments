#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

template<class T>
class CLL{
    private:
    struct Node
    {
    T data;
    Node* next;
    Node(T value){
        data = value;
        next = NULL;
    }   
       /* data */

    };
        Node *head;
    public:
    CLL(){
        head = NULL;
    }

    void InsertAtEnd( T x){
    Node *temp = new Node(x);
    if(head==NULL){
        temp->next = temp;
        head = temp;
    }
    else{
        temp->next = head->next;
        head->next = temp;
        T t = temp->data;
        temp->data = head->data;
        head->data =t;
        head = temp;
        return;
    }
}
    void deleteKthNode( int k){
    if(head==NULL) return;
    if(k==1){
        delete(head);
        head = NULL;
    }
    Node *curr = head;
    for(int i =0;i<k-2;i++) curr = curr->next;
    Node *temp = curr->next;
    curr->next = temp->next;
    delete(temp);
    return;
}
    void PrintList(){
    if(head==NULL) return;
    Node *p = head;
    do{
        cout<<p->data<<" ";
        p = p->next;
    }while(p!=head);

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
        CLL<int> my_list;
        for(int j=1;j<=i;j++) my_list.InsertAtEnd(j);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<duration.count()<<" ";
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
    CLL<string> cl;
    cl.InsertAtEnd("means");
    cl.InsertAtEnd("hello");
    cl.InsertAtEnd("henlo");
    cl.PrintList();
    cl.deleteKthNode(2);
    cl.PrintList();
    return 0;
}