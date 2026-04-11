// Implementation of a data structure that supports insert, remove, and getRandom operations in O(n) time, allowing duplicates.

// Example 1:
// Input
// ["RandomizedCollection", "insert", "insert", "insert", "getRandom", "remove", "getRandom"]
// [[], [1], [1], [2], [], [1], []]
// Output: [null, true, false, true, 1 or 2, true, 1 or 2]


#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;


class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> mp;
    vector<int> arr;

public:
    RandomizedCollection() {}

    bool insert(int val) {
        arr.push_back(val);
        mp[val].insert(arr.size() - 1);
        return mp[val].size() == 1;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end() || mp[val].empty())
            return false;

        int idx = *mp[val].begin();
        int lastIdx = arr.size() - 1;
        int last = arr.back();

        mp[val].erase(idx);

        if (idx != lastIdx) {
            arr[idx] = last;
            mp[last].erase(lastIdx);
            mp[last].insert(idx);
        }

        if (mp[val].empty()) mp.erase(val);
        arr.pop_back();
        return true;
    }

    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    RandomizedCollection* obj = new RandomizedCollection();
    cout << obj->insert(1) << endl; // true
    cout << obj->insert(1) << endl; // false
    cout << obj->insert(2) << endl; // true
    cout << obj->getRandom() << endl; // 1 or 2
    cout << obj->remove(1) << endl; // true
    cout << obj->getRandom() << endl; // 1 or 2
    return 0;
}