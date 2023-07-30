/*#include <iostream>
using namespace std;

int main ()
{
    int arr[3][4];

    // Taking input
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 4; col++)
            cin >> arr[row][col];

    // Printing
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 4; col++)
            cout << arr[row][col] << "  ";
        cout << endl ;
    }

    // Linear Search
    int n ;
    cout << "Enter The Element to find"<< endl ;
    cin >> n ;



    return 0 ;
}
*/
#include <iostream>
using namespace std;

void rowSum(int arr[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        cout << "Sum of " << i + 1 << " row  = " << sum << endl;
    }
}
void colSum(int arr[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[j][i];
        }
        cout << "Sum of " << i + 1 << " col  = " << sum << endl;
    }
}

int main()
{
    int arr[3][3];

    // Taking input
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            cin >> arr[row][col];

    // Printing
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
            cout << arr[row][col] << "  ";
        cout << endl;
    }
    rowSum(arr, 3, 3);
    colSum(arr, 3, 3);

    return 0;
}
