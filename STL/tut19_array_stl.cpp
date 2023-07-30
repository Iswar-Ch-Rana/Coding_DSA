#include <iostream>
#include <array>
using namespace std;

int main()
{
    // Normal Array
    int arr[5] = {1, 2, 3, 4, 5};

    // STL Array
    array<int, 5> a = {1, 2, 3, 4, 5};

    //  Size Of STL Array
    int size = a.size();
    for (int i = 0; i < size; i++)
    {
        // cout << a[i] << " ";
        // Also We can Write
        cout << a.at(i) << " ";
    }
    cout << endl;

    cout << "Empty Or Not" << a.empty() << endl;
    cout << "First Element = " << a.front() << endl;
    cout << "Last Element = " << a.back() << endl;

    return 0;
}