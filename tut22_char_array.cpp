/*#include <iostream>
using namespace std;

void reversename(char name[],int len){
    for (int i = 0; i < len/2; i++)
    {
        swap(name[i],name[len-i-1]);
    }
}


int getlength(char name[]){
    int count = 0;
    for (int i = 0; '\0' != name[i]; i++)
        count++;
    return count ;
}

int main ()
{
    char name[20];
    cin >> name;
    int len = getlength(name);
    cout << "My name is "<< name << endl ;
    cout << "Name Length is "<< len << endl ;
    // Reversing my name
    reversename(name,len);
    cout << "My name After Rreverse "<< name << endl ;
    return 0 ;
} */
/*
#include <iostream>
#include <algorithm>
using namespace std;

char maxmimumchar(string s)
{
    int alpha[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        int number = 0;
        if (ch >= 'a' && ch <= 'z')
        {
            number = ch - 'a';
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            number = ch - 'A';
        }
        alpha[number]++;
    }
    int maxi = -1, ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < alpha[i])
        {
            ans = i;
            maxi = alpha[i];
        }
    }
    char f_ans = ans + 'a';
    return f_ans;
}

int main()
{
    string s;
    cin >> s;
    char ch = maxmimumchar(s);

    cout << "The Most repeated element in array = " << ch << endl;
    return 0;
}

*/

// Home work
#include <iostream>
#include <string>
using namespace std;

string replaceSpaces(string str)
{
    int length = str.size();
    for (int i = 0; i < length; i++)
    {
        char ch = str[i];
        if (ch == 32)
        {
            int start = i;
            int end = length - 1;
            // shift
            for (; end >= start; end++)
            {
                str[end + 3] = str[end];
                end--;
            }
            end = end+3;
            str[i] = '@';
            str[i+1] = '4';
            str[i+2] = '0';
        }
    }
    return str;
}
int main()
{
    string stri = "I love coding";
    string strin = replaceSpaces(stri);
    cout << strin << endl;
}