// Heap Sort

#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &A, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && A[left] > A[largest])
        largest = left;

    if (right < n && A[right] > A[largest])
        largest = right;

    if (largest != i)
    {
        swap(A[i], A[largest]);
        heapify(A, n, largest);
    }
}

void heapSort(vector<int> &A)
{
    int n = A.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}

int main()
{
    vector<int> A = {12, 11, 13, 5, 6, 7};
    heapSort(A);
    cout << "Sorted array is: ";
    for (int i : A)
        cout << i << " ";
    cout << endl;
}

// Time Complexity: O(n log n) because building the heap takes O(n) time and each of the n elements is extracted from the heap, which takes O(log n) time.
// Space Complexity: O(1) as we are sorting the array in place and using only a constant amount of extra space for temporary variables during heapification and swapping.