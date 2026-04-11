// Minimum Addition to Make Integer Beautiful

// You are given two positive integers n and target.
// An integer is considered beautiful if the sum of its digits is less than or equal to target.
// Return the minimum non-negative integer x such that n + x is beautiful. The input will be generated such that it is always possible to make n beautiful.

// Example 1:
// Input: n = 16, target = 6
// Output: 4
// Explanation: The sum of digits of 16 is 1 + 6 = 7, which is greater than 6. We can add 4 to 16 to get 20, which is beautiful because the sum of its digits is 2 + 0 = 2,
// which is less than or equal to 6. It can be shown that there is no smaller x that makes n beautiful.

// Example 2:
// Input: n = 467, target = 6
// Output: 33
// Explanation: The sum of digits of 467 is 4 + 6 + 7 = 17, which is greater than 6. We can add 33 to 467 to get 500, which is beautiful because the sum of its digits is 5 + 0 + 0 = 5, which is less than or equal to 6. It can be shown
// that there is no smaller x that makes n beautiful.

#include <iostream>

using namespace std;

int sumDigit(long long n)
{
    int sum = 0;
    while (n)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

long long makeIntegerBeautiful(long long n, int target)
{
    long long original = n, base = 1;
    while (sumDigit(n) > target)
    {
        n = n / 10 + 1;
        base *= 10;
    }
    return n * base - original;
}

int main()
{
    long long n;
    int target;
    cin >> n >> target;
    cout << makeIntegerBeautiful(n, target) << endl;
    return 0;
}


// time complexity: O(log n) where n is the input number. This is because we are dividing n by 10 in each iteration of the while loop, which reduces the number of digits by one in each step. The sumDigit function also runs in O(log n) time since it processes each digit of n.
// space complexity: O(1) since we are using only a constant amount of extra space