#include<iostream>
using namespace std;
class Node{
    public:
int data;
 Node * next;
 Node(int d){
    this ->data = d;
    this->next = NULL;
 }
};
 Node *segeration(Node * head){
    Node * evenstart = NULL;
    Node * evenend = NULL;
    Node * oddstart = NULL;
    Node * oddend = NULL;
    Node * curr = head;
    while(curr!=NULL){
        int val = curr->data;
        if(val%2==0){
            if(evenstart==NULL){
            evenstart = curr;
            evenend = evenstart;
        }
        else{
            evenend->next = curr;
            evenend = evenend->next;
        }
        }
        else{
            if(oddstart == NULL){
                oddstart = curr;
                oddend = oddstart;
            }
            else{
                oddend->next = curr;
                oddend = oddend->next;
            }
        }
        curr = curr->next;
    }
    if(oddstart==NULL || evenstart==NULL){
        return evenstart;
    }
    evenend->next = oddstart;
    oddend->next =NULL;
return evenstart;

 }
 void print(Node * node){
    while(node!=NULL){
        cout<<node->data<<endl;
        node = node->next;
    }
 }
 int main(){
    Node * head = new Node(1);
    head->next = new Node(8);
    head->next->next = new Node (2);
    head->next->next->next = new Node (3);
    head->next->next->next->next = new Node (4);
    head->next->next->next->next->next = new Node (7);
    head->next->next->next->next->next->next = new Node (6);
    head->next ->next->next->next->next->next->next= new Node (9);
    cout<<"PRINT ALL THE ORIGINAL LIST NUMBER :"<<endl;
    print(head);
cout<<"AFTER THE SEGERATION THE NUMBERS ARE :"<<endl;
head = segeration(head);
print(head);
 }
