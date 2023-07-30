#include <bits/stdc++.h>
using namespace std;

class Solution
{

    bool isSafe(int newx, int newy, vector<vector<int>> visited, vector<vector<int>> m, int n)
    {

        if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && (visited[newx][newy] == 0) && (m[newx][newy] == 1))
            return true;
        else
            return false;
    }

    void solve(int n, vector<vector<int>> &m, vector<string> &ans,
               int x, int y, vector<vector<int>> &visited, string path)
    {
        // Base Case
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(path);
            return;
        }
        // we have visited x , y
        visited[x][y] = 1;

        // 4 Choice D,U,L,R
        // Down
        int newx = x + 1;
        int newy = y;
        if (isSafe(newx, newy, visited, m, n))
        {
            path.push_back('D');
            solve(n, m, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // Left
        newx = x;
        newy = y - 1;
        if (isSafe(newx, newy, visited, m, n))
        {
            path.push_back('L');
            solve(n, m, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // Right
        newx = x;
        newy = y + 1;
        if (isSafe(newx, newy, visited, m, n))
        {
            path.push_back('R');
            solve(n, m, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // Up
        newx = x - 1;
        newy = y;
        if (isSafe(newx, newy, visited, m, n))
        {
            path.push_back('U');
            solve(n, m, ans, newx, newy, visited, path);
            path.pop_back();
        }
        visited[x][y] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> ans;

        if (m[0][0] == 0)
            return ans;

        int srcx = 0;
        int srcy = 0;

        // Initializing visited array
        vector<vector<int>> visited = m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = 0;
            }
        }

        string path = "";
        solve(n, m, ans, srcx, srcy, visited, path);
        sort(ans.begin(), ans.end());
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
