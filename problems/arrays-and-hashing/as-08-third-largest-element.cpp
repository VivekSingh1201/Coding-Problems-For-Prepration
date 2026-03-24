// Third largest element in an array

#include <iostream>
#include <climits>
using namespace std;

int main() {
    int arr[] = {10, 4, 3, 50, 23, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (n < 3) {
        cout << "Array has less than 3 elements";
        return 0;
    }

    int first = INT_MIN, second = INT_MIN, third = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] != first) {
            third = second;
            second = arr[i];
        }
        else if (arr[i] > third && arr[i] != second && arr[i] != first) {
            third = arr[i];
        }
    }

    if (third == INT_MIN)
        cout << "No distinct 3rd largest element";
    else
        cout << "3rd largest element: " << third;

    return 0;
}

// time complexity : O(n) because we are traversing the array once.
// space complexity : O(1) because we are using only three variables to store the first, second and third largest elements in the array.