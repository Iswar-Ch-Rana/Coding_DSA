#include <iostream>
#include <climits>
using namespace std;

/*int minimum(int arr[], int size)
{
    int mini = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        mini = min(mini, arr[i]);
    }
    return mini;
}

int maximum(int arr[], int size)
{
    int maxi = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}
int main()
{
    int size;
    cin >> size;
    int arr[100];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Minimum of array is = " << minimum(arr, size) << endl;
    cout << "Maximum of array is = " << maximum(arr, size) << endl;

    return 0;
}
*/

/* Sum of array

int sum(int arr[], int size)
{
    int sums = 0;
    for (int i = 0; i < size; i++)
    {
        sums = sums + arr[i];
    }
    return sums;
}

int main()
{
    int size;
    cin >> size;
    int arr[100];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "The sum of the array is = " << sum(arr, size) << endl;
}
*/

// Linear Search

/* Reverse an array

int reverse(int arr[], int size)
{
    for (int i = 0; i < size/2; i++)
    {
        int temp = arr[i] ;
        arr[i] = arr[size-1-i] ;
        arr[size-1-i] = temp ;
    }
}

int main()
{
    int size;
    cin >> size;
    int arr[100];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    reverse(arr,size) ;
    cout <<endl ;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
*/
