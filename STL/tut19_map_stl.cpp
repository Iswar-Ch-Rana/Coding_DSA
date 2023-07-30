#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, string> m;

    m[1] = "Iswar";
    m[21] = "Chandra";
    m[12] = "Rana";

    m.insert({5,"Love"});

    for (auto x : m)
    {
        cout << x.first << " " << x.second << endl ;
    }
    cout << "12 is preasent or not "<< m.count(12)<< endl ;
    
    return 0;
}