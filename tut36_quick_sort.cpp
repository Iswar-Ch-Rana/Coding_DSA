#include <iostream>
using namespace std;

int Partition(int *arr, int start, int end)
{
    // chose pivot
    int pivot = arr[start];

    // how many less the pivot element is preasent
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    // place pivot at right Position
    int pivotIndex = start + count;
    swap(arr[start], arr[pivotIndex]);

    // Placing the less value then pivot to left
    int j = start;
    int k = end;

    while (j < pivotIndex && k > pivotIndex)
    {
        while (arr[j] <= pivot)
            j++;
        while (arr[k] > pivot)
            k--;
        if (j < pivotIndex && k > pivotIndex)
        {
            swap(arr[j], arr[k]);
            j++;
            k--;
        }
    }
    return pivotIndex;
}

void QuickSort(int *arr, int start, int end)
{
    // Base Case
    if (start >= end)
        return;

    // partition of the array
    int p = Partition(arr, start, end);

    // sorting the left of p
    QuickSort(arr, start, p - 1);
    // sorting the Right of p
    QuickSort(arr, p + 1, end);
}

int main()
{
    int arr[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    QuickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}