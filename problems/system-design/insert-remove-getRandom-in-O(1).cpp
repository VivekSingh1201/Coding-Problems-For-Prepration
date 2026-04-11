// Implementation of a data structure that supports insert, remove, and getRandom operations in O(1) time.


// Example 1:

// Input
// ["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
// [[], [1], [2], [2], [], [1], [2], []]

// Output: [null, true, false, true, 2, true, false, 2]

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> mp;  // val → index in array
    vector<int> arr;             // stores all values

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (mp.count(val)) return false;  // already exists

        arr.push_back(val);
        mp[val] = arr.size() - 1;  // store index
        return true;
    }

    bool remove(int val) {
        if (!mp.count(val)) return false;  // not found

        int idx = mp[val];         // index of val in array
        int last = arr.back();     // last element

        // Swap val with last element
        arr[idx] = last;
        mp[last] = idx;            // update last's index in map

        // Remove val
        arr.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom() {
        int idx = rand() % arr.size();
        return arr[idx];           // O(1) random access 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

 int main() {
    RandomizedSet* obj = new RandomizedSet();
    cout << obj->insert(1) << endl;  // true
    cout << obj->insert(2) << endl;  // true
    cout << obj->insert(1) << endl;  // false
    cout << obj->remove(1) << endl;  // true
    cout << obj->remove(1) << endl;  // false
    cout << obj->getRandom() << endl; // 2 (only element left)
    return 0;
}

// Time Complexity: O(1) for insert, remove, and getRandom operations.
// Space Complexity: O(n) for storing the elements in the array and map.