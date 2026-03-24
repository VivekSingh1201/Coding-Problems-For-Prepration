//Given an integer array, the task is to divide the ray into three non-empty contagious segments with equal sum. In other words, we need to return an index pair[i,j] such that sum(arr[0...i]) = sum(arr[i+1...j]) = sum(arr[j+1...n-1]) where 0 < i < j < n-1. If there are multiple answers, return the one with the smallest i. If there is no answer, return [-1, -1].


// #include <iostream>
// #include<vector>
// #include <algorithm>
// #include <utility>
// using namespace std;

// int find_sum(vector<int>arr,int start,int end){
//     int sum=0;
//     for(int i=start;i<=end;i++){
//         sum+=arr[i];
//     }
//     return sum;
// }

// int main() {
//     vector<int> arr={1,1,0,3,3};
//     int n=arr.size();

//     //check the 15thimage for understanding
    
//     for(int i=0;i<=n-3;i++){
//         for(int j=i+1;j<=n-2;j++){
//             int sum1=find_sum(arr,0,i);
//             int sum2=find_sum(arr,i+1,j);
//             int sum3=find_sum(arr,j+1,n-1);
            
//             if(sum1==sum2 && sum2==sum3){
//                 cout<<i<<" "<<j;
//                 return 0;
//             }
//         }
//     }
// }

//     cout<<"-1 -1"; // if there is no answer then we will return -1 -1

    //time complexity of this approach is O(n^3) because we are using two nested loops to find the index pair and we are also using a function to find the sum of the segments which takes O(n) time complexity.
    
    


// But we by using 1/3 rd of the total sum we can find the index pair in O(n) time complexity and O(1) space complexity.

// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include <algorithm>
#include <utility>
using namespace std;


int main() {
    vector<int> arr={1,3,4,0,4};
    vector<int> res={-1,-1};
    int n=arr.size();
    
    int t_sum=0;
    
    for(int i=0;i<=n-1;i++){
        t_sum+=arr[i];
    }
    
    if(t_sum%3!=0){
        cout<<-1<<" "<<-1;
        return 0;
    }
    
    int sum=0;
    int idx=0;
    
    for(int i=0;i<=n-2;i++){
        sum+=arr[i];
        if(sum==t_sum/3){
            res[idx++]=i;
            sum=0;
            if(idx==2){
                break;
            }
        }
    }
    
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}

// time complexity of this approach is O(n) because we are traversing the array only once to find the total sum and then we are traversing the array again to find the index pair. Space complexity is O(1) because we are using only a constant amount of space to store the total sum and the index pair.