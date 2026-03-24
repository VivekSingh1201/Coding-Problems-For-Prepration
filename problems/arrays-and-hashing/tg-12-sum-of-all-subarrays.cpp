// Compute the sum of all subarrays

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     vector<int> arr = {1, 2, 3};
//     int n = arr.size();
//     int totalSum = 0;

//     for (int i = 0; i < n; i++) {
//         int subSum = 0;
//         for (int j = i; j < n; j++) {
//             subSum += arr[j];
//             totalSum += subSum;
//         }
//     }

//     cout << "Sum of all subarrays: " << totalSum;
// }

// Time Complexity: O(n^2) in the worst case, where n is the length of the array. This is because we are using two nested loops to compute the sum of all subarrays.
// Space Complexity: O(1) as we are using only a constant amount of extra space





//Optimal Approach

//Formula: Total sum += arr[i] * (i+1) * (n-i)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    long long totalSum = 0;

    for (int i = 0; i < n; i++) {
        totalSum += (long long)arr[i] * (i + 1) * (n - i);
    }

    cout << "Sum of all subarrays: " << totalSum<<endl;
}


// Time Complexity: O(n) because we are traversing the array once.
// Space Complexity: O(1) as we are using only a constant amount of extra space