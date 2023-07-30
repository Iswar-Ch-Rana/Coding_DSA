#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> prime(n + 1, true);
        int count = 0;
        prime[0] = prime[1] = false;
        for (int i = 2; i < n; i++)
        {
            if (prime[i])
            {
                count++;
                for (int j = i * 2; j < n; j = j + i)
                {
                    prime[j] = false;
                }
            }
        }
        return count;
    }
};

int main()
{
    int n;
    cout << "Enter The Number: " << endl;
    cin >> n;
    Solution s;
    int x = s.countPrimes(n);
    cout << "The Number Of prime Number is = " << x;
}