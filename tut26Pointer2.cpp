#include <iostream>
using namespace std;

int main()
{
    /*
    int arr[4] = {1,2,3,4} ;
    cout << arr << endl ; // 1st positions location of array
    cout << &arr[0] << endl ; // 1st positions location of array
    cout << &arr << endl ; // 1st positions location of array
    cout << arr[0] << endl ;
    cout << *arr << endl ;
    cout << *(arr+3) << endl ;

    int i = 3 ;
    cout << i[arr] << endl ;
    */
    char arr[6] = "abcde";
    cout << arr << endl ; // Printing entire string
    char *ptr = &arr[0];
    cout << ptr << endl ; // Printing entire string

    char temp = '8';
    char *p = &temp ;
    cout << p << endl ;


    return 0;
}