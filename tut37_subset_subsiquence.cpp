
// LeetCode 78. Subsets

class Solution
{
public:
    void solve(vector<int> nums, int index, vector<int> output, vector<vector<int>> &ans)
    {
        // Base case
        if (index >= nums.size())
        {
            ans.push_back(output);
            return;
        }
        // Exclude
        solve(nums, index + 1, output, ans);
        // Include
        int element = nums[index];
        output.push_back(element);
        solve(nums, index + 1, output, ans);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, index, output, ans);
        return ans;
    }
};

// Subsequences of String CodeSTudio

void solve(vector<string> &ans, string str, string output, int i)
{
    // base case
    if (i >= str.length())
    {
        if (output.length() > 0)
            ans.push_back(output);
        return;
    }

    // exclude
    solve(ans, str, output, i + 1);
    // include
    output.push_back(str[i]);
    solve(ans, str, output, i + 1);
}

vector<string> subsequences(string str)
{

    vector<string> ans;
    string output = "";
    solve(ans, str, output, 0);
    return ans;
}