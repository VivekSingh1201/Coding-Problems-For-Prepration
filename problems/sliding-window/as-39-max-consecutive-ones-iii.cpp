// Max Consecutive Ones III
// Given a binary array arr and an integer k, return the maximum number of consecutive 1s in the array if you can flip at most k 0's.


// approach : sliding window
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = {1, 0, 0, 1, 0, 1, 0, 1, 0};
    int k = 2;
    int n = arr.size();

    int left = 0, zeros = 0, max_sub = 0;

    for (int right = 0; right < n; right++) {
        if (arr[right] == 0)
            zeros++;

        while (zeros > k) {
            if (arr[left] == 0)
                zeros--;
            left++;
        }

        max_sub = max(max_sub, right - left + 1);
    }

    cout << max_sub<<endl;
    return 0;
}


// time complexity : O(n) because we are traversing the array once.
// space complexity : O(1) because we are using only a constant amount of extra space






// ## Dry Run — `arr = {1,0,0,1,0,1,0,1,0}`, `k = 2`
// ```
// right=0: arr[0]=1  zeros=0  window=[1]           left=0  len=1
// right=1: arr[1]=0  zeros=1  window=[1,0]         left=0  len=2
// right=2: arr[2]=0  zeros=2  window=[1,0,0]       left=0  len=3
// right=3: arr[3]=1  zeros=2  window=[1,0,0,1]     left=0  len=4
// right=4: arr[4]=0  zeros=3 > k → shrink:
//            arr[0]=1 → left=1, zeros=3
//            arr[1]=0 → left=2, zeros=2 ✓
//          window=[0,1,0]                           left=2  len=3
// right=5: arr[5]=1  zeros=2  window=[0,1,0,1]     left=2  len=4
// right=6: arr[6]=0  zeros=3 > k → shrink:
//            arr[2]=0 → left=3, zeros=2 ✓
//          window=[1,0,1,0]                         left=3  len=4
// right=7: arr[7]=1  zeros=2  window=[1,0,1,0,1]   left=3  len=5
// right=8: arr[8]=0  zeros=3 > k → shrink:
//            arr[3]=1 → left=4, zeros=3
//            arr[4]=0 → left=5, zeros=2 ✓
//          window=[1,0,1,0]                         left=5  len=4

// max_sub = 5