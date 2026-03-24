// Intersection of two two arrays
// Given two arrays, find the intersection of the two arrays. The intersection of two arrays is a list of elements that are present in both arrays.
// For example, if the first array is [1, 2, 3] and the second array is [2, 3, 4], then the intersection of the two arrays is [2, 3].

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {3,2,4};
    vector<int> res;
    

    // using unordered set to store the elements of the first array and then check if the elements of the second array are present in the set or not
    unordered_set<int> st;
    
    for(int ele : arr1){
        st.insert(ele);
    }
    
    for(int ele : arr2){
        if(st.find(ele)!=st.end()){
            res.push_back(ele);
        }
    }
    
    
    for(int ele : res){
        cout<<ele<<" ";
    }
    cout<<endl;
   

    return 0;
}

// Time complexity: O(n+m) where n and m are the sizes of the two arrays
// Space complexity: O(n) where n is the size of the first array