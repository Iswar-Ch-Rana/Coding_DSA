#include <iostream>
#include <list>
using namespace std;

int main ()
{
    list<int> l ;
    
    l.push_back(1) ;
    l.push_front(2) ;

    for (auto x : l)
        cout << x << " " ;
    cout << endl ;
    
    return 0 ;
}