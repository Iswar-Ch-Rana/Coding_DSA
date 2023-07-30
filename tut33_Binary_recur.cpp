/*Array is sorted or not

#include <iostream>
using namespace std;

bool isSorted(int arr[], int size)
{

    if (size == 0 || size == 1)
        return true;
    if (arr[0] > arr[1])
        return false;

    isSorted(arr + 1, size - 1);
    return true;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (isSorted(arr, n))
        cout << "Array is Sorted" << endl;
    else
        cout << "Array is not Sorted" << endl;
    return 0;
}
*/




/* Sum Of Array
#include <iostream>
using namespace std;

int sums(int arr[], int n, int sum)
{
    if (n == 0)
        return sum;

    sum += arr[0];
    sums(arr + 1, n - 1, sum);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sum = 0;
    int s = sums(arr, n, sum);
    cout << s << endl;

    return 0;
}
*/




