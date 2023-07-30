/*************************** Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node) **************************/
#include <iostream>
using namespace std;

class Solution
{
public:
    
    void solve(Node *root , int len , int &maxLen , int sum , int &maxSum){
        // Base Case 
        if(root == NULL){
            if(len > maxLen){
                maxLen = len ;
                maxSum = sum ;
            }else if(len == maxLen){
                maxSum= max(maxSum ,sum);
            }
            
            return ;
        }
        
        sum = sum + root->data ;
        
        solve(root->left , len+1 , maxLen , sum , maxSum);
        solve(root->right , len+1 , maxLen , sum , maxSum);
    }
    
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len = 0 ;
        int maxLen = 0 ;
        int sum = 0 ;
        int maxSum = 0 ;
        
        solve(root , len , maxLen , sum , maxSum);
        
        return maxSum ;
    }
};

/************************** 236. Lowest Common Ancestor of a Binary Tree  ******************************/


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL ;
        if(root == p || root == q)
            return root ;

        TreeNode * leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode * rightAns = lowestCommonAncestor(root->right, p, q);
        
        if(leftAns != NULL && rightAns != NULL)
            return root ;
        else if(leftAns == NULL && rightAns != NULL)
            return rightAns;
        else if(leftAns != NULL && rightAns == NULL)
            return leftAns;
        else
            return NULL ;
    }
};


/********************** 437. Path Sum III *************************/


class Solution {
public:
    void solve(TreeNode* root,vector<int>path , int target,int &count){
        if(root == NULL)
            return ;
        path.push_back(root->val);
        solve(root->left,path ,target, count);
        solve(root->right,path ,target, count);

        long sum = 0 ;
        for(int i = path.size()-1 ; i >= 0 ;i--){
            sum = sum+path[i] ;
            if(sum == target){
                count++ ;
            }
        }

        path.pop_back();
    }
    int pathSum(TreeNode* root, int target) {
        vector<int> path ;
        int count = 0 ;
        solve(root,path ,target, count);
        return count ;
    }
};


/************************ Kth Ancestor in a Tree *************************/

Node * solve(Node * root , int &k , int node){
    if(root == NULL)
        return NULL ;
    if(root->data == node)
        return root ;
        
    Node* leftAns= solve(root->left,k,node);
    Node* rightAns= solve(root->right,k,node);
    
    if(leftAns != NULL && rightAns == NULL){
        k-- ;
        if(k <= 0){
            k = INT_MAX ;
            return root ;
        }
        return leftAns ;
    }
    if(leftAns == NULL && rightAns != NULL){
        k-- ;
        if(k <= 0){
            k = INT_MAX ;
            return root ;
        }
        return rightAns ;
    }
    
    return NULL ;
}

int kthAncestor(Node *root, int k, int node)
{
    Node * ans =solve(root,k,node);
    if(ans == NULL || ans->data == node)
        return -1 ;
    else
        return ans->data ;
}


/********************* Maximum sum of Non-adjacent nodes ************************/

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int> solve(Node* root) {
        //base case
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        pair<int,int> res;
        
        res.first = root->data + left.second + right.second;
        
        res.second = max(left.first, left.second) + max(right.first, right.second);
        
        return res;
        
    }
    int getMaxSum(Node *root) 
    {
        pair<int,int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};



