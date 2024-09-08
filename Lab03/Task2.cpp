#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node * next ;
    Node (int d){
        this->data =d;
        this->next = NULL;
    }
};
Node * reverselist(Node*head){
    Node*  curr = head;
    Node *prev = NULL;
    Node *next ;
    while (curr != NULL){
next = curr->next;
curr->next = prev;
    
    prev = curr;
    curr = next;
    }
    return prev;
}
void print(Node *node){
    while(node!=NULL){
cout<<node->data<<" " <<endl;
node = node->next;
    }
}
int main(){
    Node * head = new Node (1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next= new Node(4);
    head->next->next->next->next= new Node(5);
    cout<<"original list "<<endl;
    print (head);
    cout<<"AFTER THE RECURSSION : "<<endl;
    head = reverselist (head);
    print(head);
}
