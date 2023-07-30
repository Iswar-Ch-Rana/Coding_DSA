#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;

    s.insert(10);
    s.insert(111);
    s.insert(12);
    s.insert(25);
    s.insert(10);
    s.insert(45);
    s.insert(650);

    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;

    set<int>::iterator it = s.begin();
    it++;
    s.erase(it);

    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << "10 is preasent or not " << s.count(10) << endl;
    set<int>::iterator itr = s.find(10);

    cout << "value preasent at itr->" << *it << endl;

    return 0;
}