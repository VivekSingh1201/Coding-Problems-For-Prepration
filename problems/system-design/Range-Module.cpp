// Range Module

// A Range Module is a module that tracks ranges of numbers. Design a data structure to track the ranges represented as half-open intervals and query about them.

// A half-open interval [left, right) denotes all the real numbers x where left <= x < right.

// Implement the RangeModule class:

// RangeModule() Initializes the object of the data structure.
// void addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval. Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval [left, right) that are not already tracked.
// boolean queryRange(int left, int right) Returns true if every real number in the interval [left, right) is currently being tracked, and false otherwise.
// void removeRange(int left, int right) Stops tracking every real number currently being tracked in the half-open interval [left, right).



#include <iostream>
#include <map>
#include <vector>

using namespace std;


class RangeModule {
private:
    map<int,int> intervals; // start → end of each tracked interval

public:
    RangeModule() {}

    void addRange(int left, int right) {
        // Find all intervals that overlap with [left, right)
        auto it = intervals.lower_bound(left);

        // Check if previous interval overlaps
        if (it != intervals.begin()) {
            --it;
            if (it->second < left) ++it; // no overlap, move forward
        }

        // Merge all overlapping intervals
        while (it != intervals.end() && it->first <= right) {
            left  = min(left,  it->first);
            right = max(right, it->second);
            it = intervals.erase(it);
        }

        intervals[left] = right;
    }

    bool queryRange(int left, int right) {
        // Find interval whose start <= left
        auto it = intervals.upper_bound(left);
        if (it == intervals.begin()) return false;
        --it;
        // Check if this interval fully covers [left, right)
        return it->second >= right;
    }

    void removeRange(int left, int right) {
        // Find all intervals overlapping [left, right)
        auto it = intervals.lower_bound(left);

        if (it != intervals.begin()) {
            --it;
            if (it->second <= left) ++it; // no overlap
        }

        vector<pair<int,int>> toAdd;

        while (it != intervals.end() && it->first < right) {
            // Save leftover pieces OUTSIDE [left,right)
            if (it->first < left)
                toAdd.push_back({it->first, left});
            if (it->second > right)
                toAdd.push_back({right, it->second});
            it = intervals.erase(it);
        }

        // Re-insert leftover pieces
        for (auto& [s, e] : toAdd)
            intervals[s] = e;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */

int main() {
    RangeModule* obj = new RangeModule();
    obj->addRange(10, 20);
    cout << obj->queryRange(10, 14) << endl; // true
    cout << obj->queryRange(13, 15) << endl; // true
    cout << obj->queryRange(16, 17) << endl; // true
    cout << obj->queryRange(20, 21) << endl; // false
    obj->removeRange(14, 16);
    cout << obj->queryRange(10, 14) << endl; // true
    cout << obj->queryRange(13, 15) << endl; // false
    cout << obj->queryRange(16, 17) << endl; // true
    return 0;
}