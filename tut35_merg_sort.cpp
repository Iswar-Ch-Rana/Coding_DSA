#include <iostream>
using namespace std;

void merge(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;

    // meemory for left and right array
    int *first = new int[len1];
    int *second = new int[len2];

    // Copy Elements of 1st array

    // Main array ra left kauthu start hela
    int k = start;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }

    // Copy Elements of 2nd array

    // Main array ra Right kauthu start hela
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }

    // Merging 2 sorted array

    int index1 = 0;
    int index2 = 0;

    int arrayIndex = start;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
            arr[arrayIndex++] = first[index1++];
        else
            arr[arrayIndex++] = second[index2++];
    }
    while (index1 < len1)
    {
        arr[arrayIndex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[arrayIndex++] = second[index2++];
    }
    delete[]first;
    delete[]second;
}
void MergeSort(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;

    // Base case
    if (start >= end)
        return;

    // Left Part Sort
    MergeSort(arr, start, mid);
    // Right Part Sort
    MergeSort(arr, mid + 1, end);

    // Merging the array
    merge(arr, start, end);
}

int main()
{
    int arr[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    MergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
