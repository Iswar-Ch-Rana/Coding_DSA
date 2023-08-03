#include <bits/stdc++.h>
using namespace std;

/**************** 105. Construct Binary Tree from Preorder and Inorder Traversal *****************/

class Solution {
public:
    int pos(vector<int>in,int ele ,int size){
        for(int i = 0 ; i < size ; i++){
            if(in[i] == ele)
                return i ;
        }
        return -1 ;
    }
    TreeNode* solve(vector<int>pre, vector<int>in, int &preIndex,int inStart, int inEnd , int size){
        if(preIndex >= size || inStart > inEnd)
            return NULL ;

        int element = pre[preIndex++];
        int position = pos(in,element,size);
        TreeNode* root = new TreeNode(element);

        root->left = solve(pre,in,preIndex,inStart,position-1,size);
        root->right = solve(pre,in,preIndex,position+1,inEnd,size);

        return root ;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int size = pre.size();
        int preIndex = 0 ;
        TreeNode* ans = solve(pre,in,preIndex,0,size-1,size);
        return ans;
    }
};


/********************* 106. Construct Binary Tree from Inorder and Postorder Traversal ***********************/


class Solution {
public:
    int search(vector<int>v,int x)
    {
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==x)
            return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& inorder,vector<int>& postorder,int& postindex,int inorderstart,int inorderend)
    {
        if(postindex<0||(inorderstart>inorderend))
        return NULL;

        TreeNode* root=new TreeNode(postorder[postindex--]);
        int pos=search(inorder,root->val);
        root->right=solve(inorder,postorder,postindex,pos+1,inorderend);
        root->left=solve(inorder,postorder,postindex,inorderstart,pos-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postindex=postorder.size()-1;
        int inorderstart=0;
        int inorderend=postorder.size()-1;
        return solve(inorder,postorder,postindex,inorderstart,inorderend);
    }
};

