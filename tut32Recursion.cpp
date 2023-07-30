/* Fibonacci no 0 1 1 2 3 5 8 13 21
#include <iostream>
using namespace std;

int fibonacci(int n){

    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int ans = fibonacci(n-1)+fibonacci(n-2);
    return ans;

}

int main ()
{
    int n ;
    cin >> n ;
    int ams = fibonacci(n);
    cout << ams<< endl ;
        return 0 ;
}*/

// 214  o/p = Two One Four

#include <iostream>
using namespace std;

void Digit(int n, string arr[])
{
    if (n == 0)
        return;

    int digit = n % 10;
    n = n / 10;

    Digit(n, arr);

    cout << arr[digit] << " ";
}

int main()
{
    int n;
    cin >> n;
    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    Digit(n, arr);
    return 0;
}
