#include<iostream>
#include<cstring>
using namespace std;
class Document{
private:
char *content;
public:
Document(const char* initialcontent){
    if(initialcontent){
    content = new char[strlen(initialcontent)+1];
    strcpy(content , initialcontent);
}
else{
    content = nullptr;
}
}
~Document(){
delete[] content  ;
} 
// copy constructor 
Document (const Document &other){
if(other.content){
content = new char [strlen(other.content)+1];
strcpy(content , other.content);
}
else{
    content = nullptr;
}
}
//operator assigned constructor
Document& operator = (const Document &other ){
    if(this == &other){
       return *this;
    }
    delete[] content;
if(other.content){
content = new char [strlen(other.content)+1];
strcpy(content , other.content);
}
else{
    content = nullptr;
}
return *this;
}
// set content
void setcontent(const char* newcontent){
    delete[] content;
    if(newcontent){
    content = new char [strlen(newcontent)+1];
    strcpy(content , newcontent);
    }
    else{
        content = nullptr;
    }
    
}
// displaying content 
void display() const {
    if(content){
        cout<<"DOCUMENT CONTENT : "<<content<<endl;
    }
    else{
        cout<<"DOCUMENT IS EMPTY: "<<endl;
    }
}
};
int main(){
    Document doc1("oridinal content");
    cout<<"ORIGINAL DOCUMENT CONTENT (DOC1) : "<<endl;
    doc1.display();

    Document doc2 = doc1;
    cout<<" COPIED DOCUMENTS (DOC2) USING COPY CONSTRUCTOR : "<<endl;
    doc2.display();

    Document doc3 = doc1;
    cout<<"ASSIGENED DOCUMENT (DOC2) USING ASSIGEMENT OPERATOR :  "<<endl;
    doc3.display();
    
    doc1.setcontent("MODIFIED ORIGINAL DOCUMENT");
    cout<<"MODIFIED ORIGINAL DOCUMENT (DOC1) "<<endl;
    doc1.display();
     
     cout<<"COPYED DOCUMENT (DOC2) AFTER MODIFIED ORIGINAL DOCUMENTS "<<endl;
     doc2.display();

    cout<<"ASSIGENED  DOCUMENT (DOC3) AFTER MODIFIED ORIGINAL DOCUMENTS "<<endl;
     doc3.display();

}
