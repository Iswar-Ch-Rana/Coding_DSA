/* Decimal and Binary number system
#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
    int n , ans =0 , i = 0;
    cout << "Enter Your Number " << endl ;
    cin >> n ;
    while (n != 0)
    {
        int bit = n & 1;
        ans = (bit * pow (10,i))+ ans;
        n = n >> 1;
        i++ ;
    }
    cout << "Answer is " << ans << endl ;
    return 0 ;
} 
*/

/* Binary To decimal

#include <iostream>
#include<math.h>
using namespace std;

int main ()
{
    cout << "Enter The Binary Numbers" << endl ;
    int n , i = 0, ans = 0;
    cin >> n ;
    while (n != 0)
    {
        int bit = n%10 ;
        if (bit == 1)
        {
            ans = ans+pow(2,i);
        }
        else
        {
            
        }
    n = n /10 ;
    i++ ;
    }
    cout << ans << endl ;
    
    return 0 ;
}
*/

