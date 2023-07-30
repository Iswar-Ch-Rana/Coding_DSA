/************************** 104. Maximum Depth of Binary Tree ( Height of tree ) *****************************/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        ios::sync_with_stdio(0);
        if(root == NULL)
            return 0 ;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        int ans = max(left,right)+1 ;
        
        return ans ;
    }
};



/************************** 543. Diameter of Binary Tree *****************************/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int height(TreeNode* root){
        if(root == NULL)
            return 0 ;

        int left = height(root->left);
        int right = height(root->right);

        int ans = max(left,right)+1 ;
        return ans ;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;

        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = height(root->right) + height(root->left) ;

        return max(op1,max(op2,op3));

    }
};



/************************ Level Order Traversal ***********************/



vector<int> getLevelOrderTraversal(Node* root) {
    // add your logic here
	vector<int> ans ;
	queue<Node*> q ;
	
	q.push(root);
	
	while(!q.empty()){
		Node * curr = q.front();
		q.pop();
		if(curr->left != NULL)
			q.push(curr->left);
		
		if(curr->right != NULL)
			q.push(curr->right);
		
		ans.push_back(curr->data);
		
	}
	
	return ans;
}



/************************ 110. Balanced Binary Tree ***********************/



class Solution {
    private:
        int height(TreeNode* root){
            if(root == NULL)
                return 0 ;
            int left = height(root->left);
            int right = height(root->right);
            int ans =  max(left,right)+1 ;

            return ans ;
        }
public:
    bool isBalanced(TreeNode* root) {
        // Base Case
        if(root == NULL)
            return true ;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        bool diff = abs( height(root->left) - height(root->right) ) <= 1;

        if(left && right && diff)
            return true ;
        else
            return false ;
    }
};


/******************** 100. Same Tree ************************/



class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true ;
        if((p == NULL && q != NULL) || (q == NULL && p != NULL))
            return false ;

        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);

        bool value = (p->val == q->val);

        if(left && right && value)
            return true ;
        else
            return false ;
    }
};




/******************** Sum Tree ************************/




class Solution
{
    public:
    pair<bool,int> isSum(Node * root){
        if(root == NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        if(root->left == NULL && root->right == NULL){
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        }
        
        // recursuion
        pair<bool,int>leftAns = isSum(root->left);
        pair<bool,int>rightAns = isSum(root->right);
        
        bool left = leftAns.first;
        bool right = rightAns.first;
        
        bool cond = root->data == leftAns.second + rightAns.second ;
        
        pair<bool,int>ans;
        
        if(left && right && cond){
            ans.first = true ;
            ans.second = 2*root->data ;
        }else{
            ans.first = false ;
        }
        return ans ;
    }
    
    
    
    bool isSumTree(Node* root)
    {
         return isSum(root).first ;
    }
};