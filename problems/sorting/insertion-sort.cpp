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

    // Insertion Sort   
    for(int i=0;i<n;i++){
        int key = A[i];
        int j = i-1;
        while(j>-1 && A[j]<key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }

    for(int i=0;i<n;i++){
        cout<<A[i]<<"\n";
    }

    return 0;
}