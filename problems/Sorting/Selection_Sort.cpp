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
    
    //Selection Sort
    for(int i=0;i<n;i++){
        int min_ind=i;
        for(int j=i;j<n;j++){
            if(A[j]<A[min_ind]){
                min_ind=j;
            }
        }
        swap(A[min_ind],A[i]);
    }

    for(int i=0;i<n;i++){
        cout<<A[i]<<"\n";
    }

    return 0;
}