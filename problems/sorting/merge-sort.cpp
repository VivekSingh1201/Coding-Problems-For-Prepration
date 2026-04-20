// Merge Sort

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &A, int left, int mid, int right)
{
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
    {
        if (A[i] < A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }

    while (i <= mid)
        temp[k++] = A[i++];

    while (j <= right)
        temp[k++] = A[j++];

    for (i = left; i <= right; i++)
        A[i] = temp[i - left];
}

void mergeSort(vector<int> &A, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

int main()
{
    vector<int> A = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(A, 0, A.size() - 1);
    cout << "Sorted array is: ";
    for (int i : A)
        cout << i << " ";
    cout << endl;
}


// Time Complexity: O(n log n) because we are dividing the array into halves log n times and merging takes O(n) time.
// Space Complexity: O(n) due to the temporary array used for merging.