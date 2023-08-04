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
    int findpos(vector<int> &inorder, int ele,int n){
         for(int i=0;i<n;i++){
             if(inorder[i]==ele){
                 return i;
             }
         }
         return -1;
    }
    TreeNode* solve(vector<int> &inorder, vector<int> &postorder,int &index,int start,int end,int n){
        if(index< 0 || start>end) return nullptr;
        int ele = postorder[index--];
        int pos = findpos(inorder,ele,n);

        TreeNode* temp = new TreeNode(ele);
          temp->right = solve(inorder,postorder,index,pos+1,end,n);

        temp->left = solve(inorder,postorder,index,start,pos-1,n);
      
        return temp;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = postorder.size();
        int index=n-1;
        TreeNode* ans = solve(inorder,postorder,index,0,n-1,n);
        return ans;
    }
};
