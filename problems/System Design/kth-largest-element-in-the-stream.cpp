// kth Largest Element in a Stream

// You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.
// You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.
// Implement the KthLargest class:
// KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
// int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.


// Example 1:

// Input:
// ["KthLargest", "add", "add", "add", "add", "add"]
// [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

// Output: [null, 4, 5, 5, 8, 8]

// Explanation:

// KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
// kthLargest.add(3); // return 4
// kthLargest.add(5); // return 5
// kthLargest.add(10); // return 5
// kthLargest.add(9); // return 8
// kthLargest.add(4); // return 8

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class KthLargest {
private:
    priority_queue<int,vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;

        for(int num:nums){
            add(num);
        }
    }
    
    int add(int val) {
        if(minHeap.size() < k || minHeap.top()<val){
            minHeap.push(val);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

 int main() {
    vector<int> nums={4, 5, 8, 2};
    KthLargest* obj = new KthLargest(3, nums);
    cout<<obj->add(3)<<endl; // return 4
    cout<<obj->add(5)<<endl; // return 5
    cout<<obj->add(10)<<endl; // return 5
    cout<<obj->add(9)<<endl; // return 8
    cout<<obj->add(4)<<endl; // return 8
    return 0;
}

// time complexity: O(n log k) for initialization and O(log k) for each add operation, where n is the number of initial scores and k is the number of top scores to maintain. The space complexity is O(k) for the min-heap.
// space complexity: O(k) for the min-heap that stores the top k scores.