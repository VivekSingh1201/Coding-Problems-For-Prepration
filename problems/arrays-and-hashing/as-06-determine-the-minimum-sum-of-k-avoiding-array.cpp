// Determine the Minimum Sum of a K-Avoiding Array

// You are given two integers, n and k.
// An array of distinct positive integers is called a k-avoiding array if there does not exist any pair of distinct elements that sum to k.
// Return the minimum possible sum of a k-avoiding array of length n.

// Example 1:
// Input: n = 4, k = 5
// Output: 14
// Explanation: One possible k-avoiding array of length 4 is [1, 2, 5, 6]. The sum of this array is 14. It can be shown that there is no k-avoiding array of length 4 with a smaller sum.



// Dry Run

// n = 4, k = 5

// picked = {}  set to store the picked numbers
// sum = 0
// count = 0
// num = 1

// --- Iteration 1 ---
// num = 1
// k - num = 5 - 1 = 4
// Is 4 in picked? No
// Pick 1 → picked = {1}, sum = 1, count = 1
// num = 2

// --- Iteration 2 ---
// num = 2
// k - num = 5 - 2 = 3
// Is 3 in picked? No
// Pick 2 → picked = {1, 2}, sum = 3, count = 2
// num = 3

// --- Iteration 3 ---
// num = 3
// k - num = 5 - 3 = 2
// Is 2 in picked? Yes → Skip
// num = 4

// --- Iteration 4 ---
// num = 4
// k - num = 5 - 4 = 1
// Is 1 in picked? Yes → Skip
// num = 5

// --- Iteration 5 ---
// num = 5
// k - num = 5 - 5 = 0
// Is 0 in picked? No
// Pick 5 → picked = {1, 2, 5}, sum = 8, count = 3
// num = 6

// --- Iteration 6 ---
// num = 6
// k - num = 5 - 6 = -1
// Is -1 in picked? No
// Pick 6 → picked = {1, 2, 5, 6}, sum = 14, count = 4
// num = 7

// --- count = 4 = n → STOP ---

// Answer = 14 

#include <iostream>
#include <set>

using namespace std;

long long minimumSum(int n, int k)
{
    set<int> picked;
    long long sum = 0;
    int num = 1;


// We keep picking numbers starting from 1 and check if their complement (k - num) has already been picked. If it hasn't, we add the number to our set of picked numbers and add it to our sum. 
//We continue this process until we have picked n numbers for our k-avoiding array.
    while (picked.size() < n)
    {
        if (picked.find(k - num) == picked.end())
        {
            picked.insert(num);
            sum += num;
        }
        num++;
    }

    return sum;
}

int main()
{
    int n = 5, k = 4;
    cout << "Minimum possible sum of a k-avoiding array of length n is:- " << minimumSum(n, k) << endl;
    return 0;
}

// time complexity: O(n)
// space complexity: O(n) due to the set storing the picked numbers
