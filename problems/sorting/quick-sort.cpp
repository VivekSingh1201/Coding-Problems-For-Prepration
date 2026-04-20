// Quick Sort

#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int> &A, int low, int high)
{
    if (low < high)
    {
        int pivot = A[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (A[j] < pivot)
            {
                i++;
                swap(A[i], A[j]);
            }
        }
        swap(A[i + 1], A[high]);
        int pi = i + 1;

        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

int main()
{
    vector<int> A = {10, 7, 8, 9, 1, 5};
    int n = A.size();
    quickSort(A, 0, n - 1);
    cout << "Sorted array is: ";
    for (int i : A)
        cout << i << " ";
    cout << endl;
}

// Time Complexity: O(n log n) on average and O(n^2) in the worst case when the smallest or largest element is always chosen as the pivot.
// Space Complexity: O(log n) on average due to recursive stack space, and O(n) in the worst case.