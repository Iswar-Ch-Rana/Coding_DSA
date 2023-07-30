#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a ;
}
int lcm (int gcd,int a , int b){
    return (a*b)/gcd ;
}

int main()
{
    int n1, n2;
    cout << "Enter The 1st Number : " << endl;
    cin >> n1;
    cout << "Enter The 2nd Number : " << endl;
    cin >> n2;

    int ans = gcd(n1, n2);
    int LCM = lcm(ans,n1,n2);
    cout << "The GCD of " << n1 << " & " << n2 << " = " << ans << endl;
    cout << "The LCM of " << n1 << " & " << n2 << " = " << LCM << endl;

    // Formula of LCM and GCD
    // LCM * GCD = a*b
}