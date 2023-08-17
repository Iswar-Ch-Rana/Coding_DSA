#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> array_of_string(string s)
{
    int i = 0;
    vector<string> ans;
    string temp = "";
    while (i < s.length())
    {
        char ch = s[i];
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
        {
            temp += ch;
            i++;
        }
        else
        {
            ans.push_back(temp);
            temp = "";
            i++;
        }
    }
    return ans;
}

int main()
{
    vector<string> ans = array_of_string("He is a it's how.is ");
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << endl;
    return 0;
}