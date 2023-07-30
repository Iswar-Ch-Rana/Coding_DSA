#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<string> q;
    q.push("Iswar");
    q.push("Chandra");
    q.push("Rana");

    cout << "First element -> "<< q.front() << endl ;
    q.pop() ;
    cout << "First element -> "<< q.front() << endl ;

    return 0;
}