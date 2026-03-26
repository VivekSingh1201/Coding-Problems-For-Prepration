// Containe rwith most water
// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
// Note: You may not slant the container and n is at least 2.
// Example:
// Input: [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49. Between the lines at index 1 (height 8) and index 8 (height 7), the area is min(8,7) * (8-1) = 7 * 7 = 49.

#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum area of water that can be contained
int maxArea(vector<int>& height) {
    int left=0;
    int right=height.size()-1;
    int max_area=0;

    while(left<right){
        int area = min(height[left],height[right])*(right-left);
        max_area=max(max_area,area);

        if(height[left]<height[right]){
            left++;
        }
        else{
            right--;
        }
    }
    return max_area;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << "Maximum area of water that can be contained: " << maxArea(height) << endl;
    return 0;
}

// Time Complexity: O(n) - We traverse the array once with two pointers.
// Space Complexity: O(1) - We are using only a constant amount of extra space for the variables.