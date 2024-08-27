#include<iostream>
using namespace std;
int main(){
    int a[10][10] , b[10][10] , mult[10][10] , r1 ,c1 ,r2 ,c2 ;
    cout<<"ENTER THE  ROW AND COLUMN OF FIRST MATRIX "<<endl;
    cin>>r1>>c1;
    cout<<"ENTER THE ROW AND COLUMN OF SECOND MATRIX"<<endl;
    cin>>r2>>c2;
    while(c1!=r2){
        cout<<"COLUMN OF FIRST MATRIX NOT EQUAL TO SECOND MATRIX"<<endl;
        cout<<"ENTER THE ROW AND COLUMN OF FIRST MATRIX "<<endl;
        cin>>r1>>c1;
        cout<<"ENTER THE ROW AND COLUMN OF SECOND MATRIX "<<endl;
        cin>>r2>>c2;
    }
        // sorting elemnet of first matrix
        cout<<endl;
        cout<<"Enter the element of first matrix"<<endl;
        for(int i=0;i<r1;i++)
            for(int j=0;j<c1;j++)
{
    cout<<"ENTER ELEMNT OF A"  << i+1 << j+1 << " : " <<endl;
    cin>>a[i][j];
}        
// sorting the elemnt of second matrix 
for(int i=0;i<r2;i++)
for(int j=0;j<c2;j++){
cout<<"ENTER ELEMNT OF B "<< i+1 << j+1 << " : " <<endl;
cin>>b[i][j];
}
    // intalize the both matrix for sorting  
    for (int i=0;i<r1;i++)
    for(int j=0;j<c2;j++){
        mult[i][j] = 0;
    }
    // multiply both the matrix 
    for(int i=0;i<r1;i++)
    for(int j=0;j<c2;j++)
        for(int k=0;k<c1;k++){
            mult[i][j] +=a[i][k]*b[k][j];
    }
    // displaying the matrix 
   cout<<endl<<"OUTPUT MATRIX"<<endl;
   for(int i=0;i<r1;i++){
   for(int j=0;j<c2;j++){
    cout<<mult[i][j]<<" ";
   }
   cout<<endl;
}
}
