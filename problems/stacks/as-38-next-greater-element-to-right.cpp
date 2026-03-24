// Next Greater Element to the Right
// Given an array of integers, find the next greater element for each element in the array. The next greater element for an element x is the first greater element on the right side of x in the array. If there is no greater element for x, then the next greater element for x is -1.


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<stack>
using namespace std;

int main() {
    
    vector<int> arr={4,2,5,17,12,2};
    int n=arr.size();
    vector<int> res(n,-1);
    
    stack <int> st;
    
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top() < arr[i]){
            st.pop();
        }
        if(!st.empty()){
            res[i]=st.top();
        }
        st.push(arr[i]);
    }
    
    for(int e : res){
        cout<<e<<' ';
    }
    
    return 0;
}

// time complexity : O(n) because we are traversing the array once.
// space complexity : O(n) because in worst case, we may need to store all elements in the stack.



// Dry Run — `arr = {4, 2, 5, 17, 12, 2}
// ```
// i=5: arr[5]=2   stack=[]        → push 2   | stack=[2]       res[5]=-1
// i=4: arr[4]=12  pop 2 (2≤12)   → push 12  | stack=[12]      res[4]=-1
// i=3: arr[3]=17  pop 12 (12≤17) → push 17  | stack=[17]      res[3]=-1
// i=2: arr[2]=5   17>5            → push 5   | stack=[17,5]    res[2]=17
// i=1: arr[1]=2   5>2             → push 2   | stack=[17,5,2]  res[1]=5
// i=0: arr[0]=4   pop 2 (2≤4)    → 5>4      | stack=[17,5,4]  res[0]=5

// Output: 5 5 17 -1 -1 -1