// Eat Pizzas

// You are given an integer array pizzas of size n, where pizzas[i] represents the weight of the ith pizza. Every day, you eat exactly 4 pizzas. Due to your incredible metabolism, when you eat pizzas of weights W, X, Y, and Z, where W <= X <= Y <= Z, you gain the weight of only 1 pizza!

// On odd-numbered days (1-indexed), you gain a weight of Z.
// On even-numbered days, you gain a weight of Y.
// Find the maximum total weight you can gain by eating all pizzas optimally.

// Note: It is guaranteed that n is a multiple of 4, and each pizza can be eaten only once.

// Example 2:
// Input: pizzas = [1,2,3,4,5,6,7,8,]
// Output: 12
// Explanation: One optimal way to eat all the pizzas is:
// - On the first day, eat pizzas with weights 1, 2, 3, and 8. You gain a weight of 8.
// - On the second day, eat pizzas with weights 4, 5, 6, and 7. You gain a weight of 6.
// The total weight gained is 8 + 6 = 14.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long long maxWeight(vector<int> &pizzas)
{
    sort(pizzas.begin(), pizzas.end(), greater<int>());

    int days = pizzas.size() / 4;
    int oddDays = (days + 1) / 2;
    int evenDays = days / 2;

    long long total = 0;

    int ptr = 0;


    // Eat pizzas on odd days
    for (int i = 0; i < oddDays; i++)
    {
        total += pizzas[ptr++];
    }

    // Eat pizzas on even days
    for (int i = 0; i < evenDays; i++)
    {
        ptr++;
        total += pizzas[ptr++];
    }

    return total;
}


int main()
{
    vector<int> pizzas = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    cout << "Maximum total weight gained is:- " << maxWeight(pizzas) << endl;
    return 0;
}

// time complexity: O(n log n) due to sorting
// space complexity: O(1)