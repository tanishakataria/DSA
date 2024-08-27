#include<iostream>
#include<cstring>
using namespace std;
class Exam{
    private:
    char*studentname;
    char*examdate;
    float score;
    public:
    Exam (const char*name , const char*date,float sc){
        studentname = new char [strlen(name)+1];
        strcpy(studentname , name);
        examdate = new char [strlen(date)+1];
        strcpy(examdate , date);
        score = sc;
    }
    ~Exam(){
        delete[] studentname;
        delete [] examdate;
    }
    void setstudentname(const char*name){
        delete [] studentname;
        studentname = new char[strlen(name)+1];
        strcpy(studentname , name);
    }
        void setexamdate(const char*date){
            delete[]examdate;
        examdate = new char[strlen(date)+1];
        strcpy(examdate , date);
        }
        void setscore(float sc){
            score = sc;
        }
        void displaydetails(){
            cout<<"Student name :" <<studentname<<endl;
            cout<<"Exam date :" <<examdate<<endl;
            cout<<"Score :" <<score<<endl;
        }
};
int main(){
    Exam exam1("Tanisha","2024-4-13",86);
    cout<<"Original exam object is :"<<endl;
    exam1.displaydetails();
    Exam exam2 = exam1;
    cout<<"Shallow copy Exam object :"<<endl;
    exam2.displaydetails();
}
