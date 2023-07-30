#include <iostream>
using namespace std;

int pivotarry(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] >= arr[0])
            start = mid + 1;
        else
            end = mid;
    }
    return start;
}

int main()
{
    int arr[100];
    int size;
    cout << "Enter The size of array" << endl;
    cin >> size;

    for (int i = 0; i < size; i++)
        cin >> arr[i];

    // array printing
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "\"Pivot Element is \"" << pivotarry(arr, size) << endl;
    return 0;
}