// Maximum Number of Consecutive Values You Can Make
// You are given an integer array coins of length n which represents the coins that you have. The value of the ith coin is coins[i]. You can make some value x if you can choose some of your coins such that their sum equals x.
// Return the maximum number of consecutive integer values that you can make with your coins starting from and including 0.

// Example 1:
// Input: coins = [1,3]
// Output: 2
// Explanation: You can make the following values:
// - 0: take no coins
// - 1: take the first coin
// You can make 2 consecutive integer values starting from 0.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getMaximumConsecutive(vector<int>& coins) {
        int res=1;
        sort(coins.begin(),coins.end());
        for(int coin : coins){
            if(coin>res) break;
            res+=coin;
        }
        return res;
    }

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout << getMaximumConsecutive(coins) << endl;
    return 0;
}

// time complexity: O(n log n) due to the sorting step, where n is the number of coins. The rest of the operations run in O(n) time.
// space complexity: O(1) 