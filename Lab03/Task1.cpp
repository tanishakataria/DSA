#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(int d){ // constructor 
        this ->data = d;
        this ->next = NULL;
    }
    // destructor
    ~ Node(){
int value = this->data;
if(this->next != NULL){
delete next;
this -> next = NULL;
}
cout<<"memory is free for node with"<<value<<endl;
 }
};
void insertathead(Node *&head , int d){
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertattail(Node* &tail , int d){
    Node * temp = new Node(d);
    if(tail){
    tail->next = temp ;
    }
    tail = temp;
}
void print(Node * &head){
    Node * temp = head;
    while(temp !=NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}
void insertatmiddle(Node * &head , Node* &tail,int position , int d){
    if(position==1){
        insertathead(head,d);
        return;
    }
    Node * temp = head;
    int cnt = 1;
    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertattail(tail,d);
        return;
    }
    Node * nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}
void deletenode(Node* &head , int position){
    if (position == 1){
        Node * temp = head;
        head = head->next;
        temp->next = NULL;
        // memoey free
        delete temp;
    }
    else{
        Node * prev = NULL;
        Node * curr = head;
        int cnt = 1;
        while(cnt<position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main(){
    Node * node1 = new Node(10);
    Node * head = node1;
    Node * tail = node1;
    print(head);
    cout<<endl;

    insertattail(tail , 15);
    print(head);
    cout<<"after insert head "<<endl;

    insertattail(tail , 16);
    print(head);
    cout<<"after insert tail "<<endl;

    insertatmiddle(head , tail , 3 , 22);
    print(head);
    cout<<"after insert the middle  "<<endl;

    cout<<"head"<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;
    cout<<"THE HEAD AND TAIL ARE:"<<endl;
    cout<<endl;
    cout<<"AFTER DELETE THE NODE"<<endl;
    deletenode(head , 2);
    print (head);
}
