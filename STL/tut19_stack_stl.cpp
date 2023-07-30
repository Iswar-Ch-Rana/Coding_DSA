#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<string> s;
    s.push("Iswar");
    s.push("Chandra");
    s.push("Rana");

    cout << "Top Element is = " << s.top() << endl;

    s.pop();

    cout << "Top Element is = " << s.top() << endl;
    cout << "Size->" << s.size() << endl;
    cout << "Is Empty Or Not " << s.empty() << endl;
    return 0;
}