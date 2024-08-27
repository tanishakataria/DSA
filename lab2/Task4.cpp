#include<iostream>
using namespace std;
int main(){
    const int numdepartment = 4;
    const int numcourseSE = 3;
    const int numcourseAI = 4;
    const int numcourseCS = 2;
    const int numcourseDS = 1;
    // initalize them in array now;
    float gpa[numdepartment][4];
    const char*departmentname [numdepartment] = {"software engneering","ARTIFICAL INTELLIGENCE","COMPUTER SCIENCE","DATA SCIENCE"};
    for(int i=0;i<numdepartment;i++){
        cout<<"ENTER THE GPA OF COURSE " <<departmentname[i]<< endl;
    int numcourse ;
    switch(i){
    case(0) :
    numcourse = numcourseSE;
    break;
    case(1):
    numcourse = numcourseAI;
    break;
    case(2):
    numcourse = numcourseCS;
    break;
   case(3):
   numcourse = numcourseDS;
   break;
    }
    for(int j=0;j<numcourse;j++){
        cout<<" course " << (j+1) <<endl;
        cin>>gpa[i][j];
    }
    cout<<endl;
    }
    // display all the details of course 
    for (int i=0;i<numdepartment;i++){
        cout<<departmentname[i]<<endl;
        int numcourse;
        switch(i){
    case(0) :
    numcourse = numcourseSE;
    break;
    case(1):
    numcourse = numcourseAI;
    break;
    case(2):
    numcourse = numcourseCS;
    break;
   case(3):
   numcourse = numcourseDS;
   break;
    }
    for(int j=0;j<numcourse;j++){
        cout<<" course " << (j+1) <<" : " << gpa[i][j] << endl;

    }

}
}
