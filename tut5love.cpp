#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    /* BIT WISE OPERATOR

    int a = 4 , b = 6;

    cout << "a & b is " << (a&b) << endl ;
    cout << "a | b is " << (a|b) << endl ;
    cout << "~a is " << ~a << endl ;
    cout << "a ^ b is " << (a^b) << endl ;
    */

    /* LEFT SHIFT OPERATOR AND RIGHT SHIFT OPERATOR
    cout << ( 17>>1 ) << endl ;
    cout << ( 17>>2 ) << endl ;
    cout << ( 19<<1 ) << endl ;
    cout << ( 21<<2 ) << endl ;
    */

    /* FIBONACCI SERIES 
    int n = 15 ;
    int a= 0 ,b = 1;
    cout << a << " " << b << " ";
    for (int  i = 1; i < n; i++)
    {
        int nextNumber = a+b;
        cout << nextNumber  << " " ;
        a = b;
        b = nextNumber ;
    }
    */

    /* PRIME NUMBER
    int a;
    cout << "Enter a Number " << endl;
    cin >> a;

    bool isPrime = 1;

    for (int i = 2; i < a; i++)
    {
        if ((a % i) == 0)
        {
            //cout << a << " is not a prime number " << endl;
            isPrime = 0;
            break;
        }
    }
    if (isPrime == 0)
    {
        cout << "Not a Prime Number " << endl;
    }
    else
    {
        cout << "Is a Prime NUmber " << endl;
    }
    */


    /* LEET CODE PROBLEMS 1281
    int n ;
    cin >> n ;
    int pro = 1;
    int sum = 0;
    while ( n!=0 )
    {
        int digit = n%10 ;
        pro = digit * pro ;
        sum = digit + sum ;
        n = n/10 ;
    }
    int ans = pro - sum ;
    cout << ans ;
    */


    /* LEET CODE PROBLEMS 191
    int n;
    cin >> n;

    int count = 0;
    while (n != 0)
    {
        // checking last bit
        if (n & 1)
        {
            count++;
        }
        n = n>>1 ;
    }
    cout << count ;*/

    return 0;
}