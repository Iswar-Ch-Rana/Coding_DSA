#include <iostream>
#include <deque>

using namespace std;

int main()
{
    // Declaring Deque
    deque<int> d;

    // Push Operation On Deque
    d.push_back(1);
    d.push_front(2);
    d.push_back(3);
    d.push_back(4);

    // printing deque array
    for (auto x : d)
        cout << x << " ";
    cout << endl;

    // Pop Operation
    // d.pop_back(); 
    // d.pop_front();
    
    cout << "Empty Or Not" << d.empty() << endl ;   

    cout << "Array Size Before Eraseing = "<< d.size() << endl ;

    d.erase(d.begin(),d.begin()+1);
    for (auto x : d)
        cout << x << " ";
    cout << endl;

    cout << "After Size Before Eraseing = "<< d.size() << endl ;

    return 0;
}