/*#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter The Value of a : " << endl;
    cin >> a;
    cout << "Enter The Value of b : " << endl;
    cin >> b;

    char c;
    cout << "Enter The Operator ( + , - , / , % , * ): " << endl;
    cin >> c;

    switch (c)
    {
    case '+':
        cout << "The Value of  a+b = " << a + b << endl;
        break;
    case '-':
        cout << "The Value of  a-b = " << a - b << endl;
        break;
    case '*':
        cout << "The Value of  a*b = " << a * b << endl;
        break;
    case '/':
        cout << "The Value of  a/b = " << a / b << endl;
        break;
    case '%':
        cout << "The Value of  a%b = " << a % b << endl;
        break;

    default:
        cout << "Enter A Valid Input" << endl;
        break;
    }
    return 0;
}*/

#include <iostream>
using namespace std;

int factorial(int x)
{
    if (x > 1)
    {
        return x * factorial(x - 1);
    }
    else
    {
        return 1;
    }
}

int nCr(int n, int r)
{
    int f = factorial(n) / factorial(r) * factorial(n - r);
    return f;
}

int main()
{
    int a, b;
    cout << "Enter The value of n : " << endl;
    cin >> a;
    cout << "Enter The value of r : " << endl;
    cin >> b;
    int ncr = nCr(a, b);
    cout << "Value of C(n,r) = " << ncr << endl;
    return 0;
}