/*#include <iostream>
using namespace std;

int factorial(int n)
{
    // Base case
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int n;
    cin >> n;
    int ans = factorial(n);
    cout << ans << endl;
    return 0;
}*/



// n square
#include <iostream>
using namespace std;

int square(int n){
    if(n == 0)
        return 1 ;
    return 2 * square(n-1);
}

int main ()
{
    int n ;
    cin >> n ;
    int ans =  square(n);
    cout << ans << endl ;
    return 0 ;
}

