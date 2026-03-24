// Delete the middle element from a stack without using any additional data structure. The stack should be modified such that the order of the remaining elements is not changed.


#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

// we must use '&' to pass the stack by reference because we want to modify the original stack and not a copy of it.

//we can use recursion to delete the middle element from the stack. We will keep popping the elements from the stack until we reach the middle element and then we will pop the middle element and then we will push the popped elements back to the stack.

void delete_mid(stack<int> &st, int mid){
    
    if(st.empty()){
        return;
    }
    
    if(mid==1){
        st.pop();
        return;
    }
    
    int temp = st.top();
    st.pop();
    
    delete_mid(st,mid-1);
    
    st.push(temp);
}

int main() {
    
    stack<int> st;
    st.push(12);
    st.push(14);
    st.push(16);
    st.push(18);
    st.push(20);
    int n = st.size();
    
    int mid = n/2 + 1;
    
    delete_mid(st,mid);
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    
    return 0;
}

// time complexity : O(n) because we are popping n/2 elements from the stack and then pushing n/2 elements back to the stack.
// space complexity : O(n) because we are using recursion and the maximum depth of the recursion will be n/2.