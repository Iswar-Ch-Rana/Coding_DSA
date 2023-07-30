#include <iostream>
using namespace std;

int binary_search(int arr[], int size, int element)
{
    int back = size - 1, front = 0;
    while (front <= back)
    {
        // This is same as (front + back)/2 Same we take this because if we add it can cross integer range can fail test case
        int mid = front + ((back - front) / 2);

        // Checking The Element is preasent or not
        if (arr[mid] == element)
            return mid;
        else if (element > arr[mid])
            front = mid + 1;
        else if (element < arr[mid])
            back = mid - 1;
    }
    return -1;
}

int main()
{
    int size;
    cin >> size;
    int arr[100];

    // Array Input
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int ele;
    cout << "Enter The Value to search in array" << endl;
    cin >> ele;

    int x = binary_search(arr, size, ele);
    if (x == -1)
    {
        cout << "Not Found In Array" << endl;
    }
    else
        cout << "Found at Position " << x + 1 << " In Array" << endl;

    return 0;
}

