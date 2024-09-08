#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node * prev;
    Node(int d){ // constructor 
        this ->data = d;
        this ->next = NULL;
        this->prev = NULL;
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
void insertathead(Node *&head , Node *&tail , int d){
	 if(head==NULL){
        Node * temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
}
void insertattail(Node* &tail ,Node * &head , int d){
	 if(tail==NULL){
        Node * temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
	
    Node * temp = new Node(d);
    if(tail){
    tail->next = temp ;
    }
    temp->prev= tail;
    tail = temp;
}
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
        insertathead(head,tail,d);
        return;
    }
    Node * temp = head;
    int cnt = 1;
    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertattail(tail,head,d);
        return;
    }
    Node * nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert = temp;
}
void deletenode(Node* &head ,Node * &tail ,int position){
    if (position == 1){
       Node * temp = head;
                temp->next->prev = NULL;
                head = temp->next;
                temp->next = NULL;
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
            curr->prev = NULL;
            prev->next= curr->next;
            curr->next = NULL;
            delete curr;
            }
        }
int main() {
    Node * head = NULL;
    Node * tail = NULL;
    print(head);
    insertathead(head , tail , 10);
    print(head);
    cout<<endl;
    insertathead(head , tail , 11);
    print(head);
    cout<<endl;
    insertattail(tail , head, 15);
    print(head);
    cout<<endl;
    insertattail(tail , head  , 16);
    print(head);
    cout<<endl;
    insertatmiddle(head , tail , 3 , 22);
    print(head);
    cout<<endl;
    cout<<"head"<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;
    cout<<endl;
    deletenode(head , tail ,2);
    print (head);
    return 0;
}
