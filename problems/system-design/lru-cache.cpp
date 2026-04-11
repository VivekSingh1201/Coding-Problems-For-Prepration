// LRU Cache Implementation
// The LRUCache class implements a Least Recently Used (LRU) cache with a specified capacity. It provides two main operations: get and put. 
// The get operation retrieves the value associated with a key if it exists in the cache, while the put operation adds a new key-value pair to the cache or updates an existing key's value. 
// If the cache exceeds its capacity, it evicts the least recently used item.

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        remove(node);
        insertFront(node);
        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            remove(node);
            insertFront(node);
        } else {
            if (mp.size() == cap) {
                Node* lru = tail->prev;
                remove(lru);
                mp.erase(lru->key);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            insertFront(newNode);
            mp[key] = newNode;
        }
    }
};

int main() {
    LRUCache cache(2); // Cache capacity of 2

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

// The above code defines the LRUCache class with methods to get and put key-value pairs while maintaining the order of usage. The main function demonstrates the usage of the LRUCache class with a series of operations.
// The implementation uses a doubly linked list to keep track of the order of usage and an unordered map for O(1) access to the nodes in the cache.


// time complexity: O(1) for both get and put operations
// space complexity: O(capacity) for storing the cache items and the map entries.