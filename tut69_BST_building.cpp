#include <iostream>
#include <queue>
using namespace std;

class Node {
    public :
        int data ;
        Node * left ;
        Node * right ;
    Node(int data){
        this->data = data ;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* InsertBst(Node* root,int d){
    if(root == NULL){
        root = new Node(d);
        return root; 
    }

    if(d < root->data){
        // Insert in left part 
        root->left = InsertBst(root->left,d);
    }
    if(d > root->data){
        // Insert in Right part 
        root->right = InsertBst(root->right,d);
    }

    return root ;
}


void levelOrder(Node* root){
    queue<Node*>q ;
    q.push(root);

    while (!q.empty())
    {
        
        int size = q.size();;
        for (int i = 0; i < size ; i++)
        {
            Node* curr = q.front();
            q.pop();
            
            cout << curr->data << " " ;

            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        cout << endl ;
    }
}


 
void inorder(Node * root){
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout << root->data << " " ;
    inorder(root->right);
}
void preorder(Node * root){
    if(root == NULL)
        return;
    
    cout << root->data << " " ;
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node * root){
    if(root == NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " " ;
}

void dataforBst(Node* &root){
    int d ;
    cin >> d ;
    while(d != -1){
        root = InsertBst(root,d);
        cin >> d ;
    }
}

int main ()
{
    Node * root = NULL ;
    cout << "Enter Data For BST"<< endl ;
    dataforBst(root);
    cout << endl << "Level Order" << endl ;
    levelOrder(root);
    cout << endl << "pre Order" << endl ;
    preorder(root);
    cout << endl << "Post Order" << endl ;
    postorder(root);
    cout << endl << "in Order" << endl ;
    inorder(root);
    return 0 ;
}