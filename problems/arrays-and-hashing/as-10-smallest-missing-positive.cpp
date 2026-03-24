// find smallest positive number missing from an unsorted array and there can be negative values also

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    vector<int> arr = {5, 3, 2, 1, 5};
    int n = arr.size();

    int missing = -1; // default value if all positive numbers from 1 to n are present

    // Step 1: Mark presence
    for (int i = 0; i < n; i++) {
        int val = abs(arr[i]);   // IMPORTANT

        if (val >= 1 && val <= n) {
            if (arr[val - 1] > 0) {
                arr[val - 1] = -arr[val - 1];
            }
        }
    }

    // Step 2: Find first positive index
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            missing = i + 1;
            break;
        }
    }

    cout << "Smallest missing positive number: " << missing << endl;
}

// time complexity : O(n) because we are traversing the array twice, once to mark the presence of the positive numbers and once to find the first positive index.
// space complexity : O(1) because we are not using any extra space to store the result of the smallest missing positive number. We are modifying the input array to mark the presence of the positive numbers.