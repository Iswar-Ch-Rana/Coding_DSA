#include <iostream>
using namespace std;

int getsum(int *arr,int n){
    int sum = 0 ;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i] ;
    }
    return sum ;
}


int main()
{
    /*Refrence variable
    int i = 5 ;
    int &j = i ;
    cout << i << endl ;
    i++ ;
    cout << i << endl ;
    j++ ;
    cout << j << endl ;
    */

    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; 
    }
    int ans = getsum(arr,n) ;
    cout << "Sum = "<< ans << endl ;
    delete []arr ;
    
    return 0;
}