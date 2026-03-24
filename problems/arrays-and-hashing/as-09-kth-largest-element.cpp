// kth largest element in an array

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int arr[] = {10, 4, 3, 50, 23, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;

    // We can use a min heap to find the kth largest element in the array. We will push the elements of the array into the min heap and if the size of the min heap exceeds k then we will pop the top element of the min heap. At the end, the top element of the min heap will be the kth largest element in the array.

    // time complexity of this approach is O(n log k) and space complexity is O(k)

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0; i < n; i++) {
        minHeap.push(arr[i]);
        if(minHeap.size() > k)
            minHeap.pop();
    }

    cout << k << "th largest element: " << minHeap.top();
}

// time complexity : O(n log k) because we are pushing n elements into the min heap and each push operation takes O(log k) time and we are also popping the top element of the min heap if the size of the min heap exceeds k which also takes O(log k) time.
// space complexity : O(k) because we are using a min heap to store the k largest elements in the array.