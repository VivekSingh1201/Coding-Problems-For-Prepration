#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter N:- ";
    cin>>n;
    int A[n];

    for(int i=0;i<n;i++){
        cout<<"Enter "<<i<<"th n:- ";
        cin>>A[i];
    }

    //Bubble Sort
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(A[j]>A[j+1]){
                swap(A[j],A[j+1]);
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<A[i]<<"\n";
    }

    return 0;
}