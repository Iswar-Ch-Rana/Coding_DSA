#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;

    // Vector Size =  5  and initializing all element with 1
    vector<int> a(5, 1);

    for (auto x : vec)
        cout << x << " ";

    cout << endl;

    // Createing a new Vector and Copping All The element Of a Vector
    vector<int> arr(a);

    for (auto x : vec)
        cout << x << " ";

    cout << endl;

    // To Check Capacity Of a Vector We can Use Capacity Function
    cout << "Capacity -> " << vec.capacity() << endl;

    vec.push_back(10);
    cout << "Capacity -> " << vec.capacity() << endl;

    vec.push_back(20);
    cout << "Capacity -> " << vec.capacity() << endl;

    vec.push_back(30);
    cout << "Capacity -> " << vec.capacity() << endl;
    cout << "Size -> " << vec.size() << endl;

    return 0;
}