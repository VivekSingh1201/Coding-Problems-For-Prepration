// Find the square root of a number using binary search

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int find_sqrt(int n){
    int start=0, end=n;
    int ans=-1;
    
    while(start<=end){
        int mid=start + (end-start) / 2;
        if(mid*mid==n){
            return mid;
        }
        else if(mid*mid < n){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}

int main() {
    
    int n;
    cout<<"Enter an integer to find sqrt = ";
    cin>>n;
    
    int res = find_sqrt(n);
    
    cout<<"\n"<<"Square Root is = "<<res<<endl;

    return 0;
}

// time complexity : O(log n) because we are using binary search to find the square root of the number.
// space complexity : O(1) because we are not using any extra space to store the result of the square root.