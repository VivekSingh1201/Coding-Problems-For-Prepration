// Range Frequency Queries

// Design a data structure to find the frequency of a given value in a given subarray.

// The frequency of a value in a subarray is the number of occurrences of that value in the subarray.

//  Implement the RangeFreqQuery class:

// RangeFreqQuery(int[] arr) Constructs an instance of the class with the given 0-indexed integer array arr.
// int query(int left, int right, int value) Returns the frequency of value in the subarray arr[left...right].
// A subarray is a contiguous sequence of elements within an array. arr[left...right] denotes the subarray that contains the elements of nums between indices left and right (inclusive).


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> indexMap; // value → sorted list of indices

public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++)
            indexMap[arr[i]].push_back(i);
    }

    int query(int left, int right, int value) {
        if (indexMap.find(value) == indexMap.end()) return 0;

        vector<int>& indices = indexMap[value];

        // First index >= left
        auto lo = lower_bound(indices.begin(), indices.end(), left);

        // First index > right → one past last valid
        auto hi = upper_bound(indices.begin(), indices.end(), right);

        return hi - lo;  // count of indices in [left, right]
    }
};


/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */

int main() {
    vector<int> arr = {12, 33, 4, 56, 22, 4, 33, 12, 34, 56};
    RangeFreqQuery* obj = new RangeFreqQuery(arr);
    cout << obj->query(0, 9, 4) << endl;   // Output: 2
    cout << obj->query(2, 5, 33) << endl;  // Output: 1
    cout << obj->query(0, 3, 12) << endl;  // Output: 1
    cout << obj->query(4, 7, 56) << endl;  // Output: 1
    cout << obj->query(0, 9, 100) << endl; // Output: 0
    return 0;
}