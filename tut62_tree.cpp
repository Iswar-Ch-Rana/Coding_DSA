#include <iostream>
#include <queue>
using namespace std;


class Node{
    public:
        int data ;
        Node * left ;
        Node * right ;

    Node(int data){
        this->data = data ;
        this->left = NULL ;
        this->right = NULL ;
    }
};

Node * BuildTree(Node * root){

    int data ;
    cout << "Enter the data for Node" << endl ;
    cin >> data ;
    root = new Node(data);

    if(data == -1)
        return NULL;

    cout << "Enter data for inserting in left of " << data << endl ;
    root->left = BuildTree(root->left);


    cout << "Enter data for inserting in right of " << data << endl ;
    root->right = BuildTree(root->right);

    return root;
}

// Bredth first search

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
}


// Creating a tree from a level order data

void buildLevelOrder(Node * &root){
    queue<Node*>qs;
    cout << "Enter Data for root Node" << endl ;
    int data ;
    cin >> data ;
    root = new Node(data);
    qs.push(root);

    while (!qs.empty()) {
        Node* temp = qs.front();
        qs.pop();

        int leftData ;
        cout << "Enter Data for left of : "<< temp->data << endl ;
        cin >> leftData ;

        if(leftData != -1){
            temp->left = new Node(leftData);
            qs.push(temp->left);
        }

        int rightData ;
        cout << "Enter Data for Right of : "<< temp->data << endl ;
        cin >> rightData ;

        if(rightData != -1){
            temp->right = new Node(rightData);
            qs.push(temp->right);
        }
    }
}














 
void inorder(Node * root){
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout << root->data << " " ;
    inorder(root->right);
}
void prenorder(Node * root){
    if(root == NULL)
        return;
    
    cout << root->data << " " ;
    prenorder(root->left);
    prenorder(root->right);
}
void postrder(Node * root){
    if(root == NULL)
        return;
    
    postrder(root->left);
    postrder(root->right);
    cout << root->data << " " ;
}

int main(){

    Node * root = NULL;

    // root = BuildTree(root) ;

    buildLevelOrder(root);

    // Level order traversal
    cout << "printing the Level Order traversal" << endl ;
    levelOrderTraversal(root);

    // cout << "printing the InOrder traversal" << endl ;
    // inorder(root);
    // cout << endl ;



    // cout << "printing the preOrder traversal" << endl ;
    // prenorder(root);
    // cout << endl ;


    // cout << "printing the postOrder traversal" << endl ;
    // postrder(root);
    // cout << endl ;

    return 0;
}







/********************** 222. Count Complete Tree Nodes ***********************/


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
    void inorder(TreeNode* root,int &count){
        if(root == NULL)
            return ;

        inorder(root->left , count);
        count++ ;
        inorder(root->right , count);
    }

    int countNodes(TreeNode* root) {
        int count = 0 ;
        inorder(root,count);
        return count ;
    }
};



/******************  Count Leaf Nodes ********************/


/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/

void inorder(BinaryTreeNode<int> * root , int & count ){
    if(root == NULL)
        return;
    
    inorder(root->left,count);
    if(root->left == NULL && root->right == NULL)
        count++ ;

    inorder(root->right,count);
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    int count = 0 ;
    inorder(root, count);
    return count ;
}
