#include<iostream>
#include<string>
using namespace std;
int main(){
    int numrows;
    cout<<"ENTER THE NUMBER OF ROWS"<<endl;
    cin>>numrows;
    string**seatingchart = new string *[numrows];
    // for single row capacity
    int *rowcapacity = new int[numrows];
    for(int i=0;i<numrows;i++){
        cout<<"ENTER THE NUMBERS OF SEATS IN ROW : " << (i+1)<< " : " << endl;
     cin>>rowcapacity[i];
     seatingchart[i] = new string[rowcapacity[i]];
    }
    cin.ignore();
    //input attendes name 
    for(int i=0;i<numrows;i++){
        cout<<"ENTER NAMES FOR THE ROW : "<<(i+1)<<" : "<<endl;
        for(int j=0;j<rowcapacity[i];j++){
            cout<<"seats : "<<(j+1)<<" : "<< endl;

getline(cin , seatingchart[i][j]);

        }
    }
    cout<<"SEATING CHART : "<< endl;
    for(int i =0;i<numrows ; i++){
        cout<<"ROWS : "<< (i+1) << " : "<<endl;
        for(int j=0;j<rowcapacity[i];j++){
            cout<<"SEATS : "<<(j+1)<< " : " << seatingchart[i][j]<<endl;
        }
        cout<<endl;
    }
    //delete allocate memory 
    for(int i=0;i<numrows;i++){
        delete [] seatingchart[i];
    }
    delete[] seatingchart;
delete[] rowcapacity;
}
