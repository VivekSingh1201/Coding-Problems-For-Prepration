// LFU Cache Implementation
// The LFUCache class implements a Least Frequently Used (LFU) cache with a specified capacity. It provides two main operations: get and put. 
// The get operation retrieves the value associated with a key if it exists in the cache, while the put operation adds a new key-value pair to the cache or updates an existing key's value. 
// If the cache exceeds its capacity, it evicts the least frequently used item. In case of a tie in frequency, it evicts the least recently used item among those with the same frequency.

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
private:
    int cap, minFreq;
    unordered_map<int, pair<int,int>> keyMap;  // key → {value, freq}
    unordered_map<int, list<int>> freqMap;      // freq → list of keys (LRU order)
    unordered_map<int, list<int>::iterator> iterMap; // key → iterator in freqMap list

    void updateFreq(int key) {
        int freq = keyMap[key].second;

        // Remove key from current frequency list
        freqMap[freq].erase(iterMap[key]);
        if (freqMap[freq].empty()) {
            freqMap.erase(freq);
            if (minFreq == freq) minFreq++;  // update minFreq
        }

        // Add key to next frequency list (front = most recent)
        freq++;
        keyMap[key].second = freq;
        freqMap[freq].push_front(key);
        iterMap[key] = freqMap[freq].begin();
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyMap.find(key) == keyMap.end()) return -1;
        updateFreq(key);
        return keyMap[key].first;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (keyMap.find(key) != keyMap.end()) {
            // Key exists → update value and frequency
            keyMap[key].first = value;
            updateFreq(key);
        } else {
            if (keyMap.size() == cap) {
                // Evict LFU → last element of minFreq list (least recent)
                int evict = freqMap[minFreq].back();
                freqMap[minFreq].pop_back();
                if (freqMap[minFreq].empty()) freqMap.erase(minFreq);
                keyMap.erase(evict);
                iterMap.erase(evict);
            }

            // Insert new key with freq = 1
            keyMap[key] = {value, 1};
            freqMap[1].push_front(key);
            iterMap[key] = freqMap[1].begin();
            minFreq = 1;  // new key always has freq 1
        }
    }
};

int main() {
    LFUCache cache(2); // capacity of 2

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // returns 1
    cache.put(3, 3); // evicts key 2
    cout << cache.get(2) << endl; // returns -1 (not found)
    cache.put(4, 4); // evicts key 3
    cout << cache.get(3) << endl; // returns -1 (not found)
    cout << cache.get(4) << endl; // returns 4

    return 0;
}


// The above code defines the LFUCache class with methods to get and put key-value pairs while maintaining the least frequently used eviction policy. The main function demonstrates the usage of the LFUCache class with a series of operations.
// The LFUCache class uses three unordered maps to manage the cache: keyMap to store key-value-frequency pairs, freqMap to maintain lists of keys for each frequency, and iterMap to keep track of the position of each key in its frequency list for efficient updates.
// The implementation ensures that both get and put operations run in O(1) time complexity, making it efficient for real-world applications where quick access to cached data is crucial.

// time complexity: O(1) for both get and put operations
// space complexity: O(capacity) for storing the cache items and their frequencies