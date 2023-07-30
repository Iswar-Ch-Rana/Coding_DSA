/*  Reverse a string
#include <iostream>
using namespace std;

void reverse_string(string &str, int start)
{
    int end = str.length()-1-start;
    if(start >= end){
        return ;
    }
    swap(str[start],str[end]);
    reverse_string(str,start+1);
}

int main()
{
    string str;
    cin >> str;
    int len = str.length();
    reverse_string(str,0);
    cout << str << endl;
    return 0;
}
*/

/*  Check Palindrom

#include <iostream>
using namespace std;

bool check(string &str,int start , int end){
    // Base Case
    if(start > end)
        return true;


    if(str[start] != str[end])
        return false ;

    // Recursion call;
    check(str,start+1,end-1);
}

int main ()
{
    string str;
    cin >> str;
    int len = str.length();
    bool che = check(str,0,len-1);

    if (che)
        cout << "This is a palindrom" << endl ;
    else
        cout << "Not a Palindrom" << endl ;


    return 0 ;
}
*/

/*  Power of a number
        odd = a * a^b/2 * a^b/2
    a^b
        even = a^b/2 * a^b/2



#include <iostream>
using namespace std;

int power(int a, int b)
{
    // Base Case
    if (b == 0)
        return 1;
    else if (b == 1)
        return a;

    // Recursive call
    int ans = power(a, b / 2);

    if (b & 1 == 1)
        return a * ans * ans;
    else
        return ans * ans;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int ans = power(a, b);

    cout << a << " to the power " << b << " = " << ans << endl;

    return 0;
}
 */

/*  Bubble sort recursive 
*/
#include <iostream>
using namespace std;

void bubble(int *arr , int size){
    // Base Case
    if(size == 0 || size == 1)
        return ;
    
    // solve One Problem 
    for (int i = 0; i < size-1; i++)
        if(arr[i] > arr[i+1])
            swap(arr[i],arr[i+1]);
    
    // Recursive call
    bubble(arr,size-1);

}

int main ()
{
    int arr[100] ;
    int n ;
    cin >> n ;
    for (int i = 0; i < n; i++)
        cin>> arr[i] ;
    
    bubble(arr,n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " " ;
    

    return 0 ;
}
