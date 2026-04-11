// All O(1) Data Structure

// Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

// Implement the AllOne class:

// AllOne() Initializes the object of the data structure.
// inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
// dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
// getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
// getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
// Note that each function must run in O(1) average time complexity.

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <list>

using namespace std;

class AllOne {
private:
    struct Bucket {
        int count;
        unordered_set<string> keys;
    };

    list<Bucket> buckets;  // DLL of buckets ordered by count
    unordered_map<string, list<Bucket>::iterator> keyMap; // key → bucket iterator

    // Insert new bucket with count after given iterator
    list<Bucket>::iterator addBucketAfter(list<Bucket>::iterator it, int count) {
        return buckets.insert(next(it), {count, {}});
    }

    // Insert new bucket with count before given iterator
    list<Bucket>::iterator addBucketBefore(list<Bucket>::iterator it, int count) {
        return buckets.insert(it, {count, {}});
    }

public:
    AllOne() {
        // Sentinel buckets at front(min) and back(max)
        buckets.push_back({0, {}});  // dummy head (count=0)
    }

    void inc(string key) {
        if (keyMap.find(key) == keyMap.end()) {
            // New key — goes into count=1 bucket
            auto head = buckets.begin();  // dummy count=0
            auto nextIt = next(head);

            if (nextIt == buckets.end() || nextIt->count != 1)
                nextIt = addBucketAfter(head, 1);

            nextIt->keys.insert(key);
            keyMap[key] = nextIt;
        } else {
            // Existing key — move to count+1 bucket
            auto curIt = keyMap[key];
            int newCount = curIt->count + 1;
            auto nextIt = next(curIt);

            if (nextIt == buckets.end() || nextIt->count != newCount)
                nextIt = addBucketAfter(curIt, newCount);

            nextIt->keys.insert(key);
            keyMap[key] = nextIt;

            // Remove key from current bucket
            curIt->keys.erase(key);
            if (curIt->keys.empty()) buckets.erase(curIt);
        }
    }

    void dec(string key) {
        if (keyMap.find(key) == keyMap.end()) return;

        auto curIt = keyMap[key];
        int newCount = curIt->count - 1;

        if (newCount == 0) {
            // Remove key entirely
            keyMap.erase(key);
        } else {
            // Move to count-1 bucket
            auto prevIt = prev(curIt);

            if (prevIt->count != newCount)
                prevIt = addBucketBefore(curIt, newCount);

            prevIt->keys.insert(key);
            keyMap[key] = prevIt;
        }

        // Remove from current bucket
        curIt->keys.erase(key);
        if (curIt->keys.empty()) buckets.erase(curIt);
    }

    string getMaxKey() {
        if (buckets.size() == 1) return "";  // only dummy
        return *buckets.back().keys.begin();
    }

    string getMinKey() {
        if (buckets.size() == 1) return "";  // only dummy
        return *next(buckets.begin())->keys.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

int main() {
    AllOne* obj = new AllOne();
    obj->inc("hello");
    obj->inc("hello");
    cout << obj->getMaxKey() << endl; // "hello"
    cout << obj->getMinKey() << endl; // "hello"
    obj->inc("leet");
    cout << obj->getMaxKey() << endl; // "hello"
    cout << obj->getMinKey() << endl; // "leet"
    obj->dec("hello");
    cout << obj->getMaxKey() << endl; // "hello" or "leet"
    cout << obj->getMinKey() << endl; // "hello" or "leet"
    return 0;
}

// Time Complexity: O(1) for all operations
// Space Complexity: O(n) where n is the number of unique keys stored in the data structure.