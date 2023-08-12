#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *InsertBst(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d < root->data)
    {
        // Insert in left part
        root->left = InsertBst(root->left, d);
    }
    if (d > root->data)
    {
        // Insert in Right part
        root->right = InsertBst(root->right, d);
    }

    return root;
}

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {

        int size = q.size();
        ;
        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();

            cout << curr->data << " ";

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        cout << endl;
    }
}

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void dataforBst(Node *&root)
{
    int d;
    cin >> d;
    while (d != -1)
    {
        root = InsertBst(root, d);
        cin >> d;
    }
}

// Min and Max Value in BST

Node *minVal(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
Node *maxVal(Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

Node *deleteFromBst(Node *root, int val)
{
    if (root == NULL)
        return root;

    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child

        // Left Child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Right Child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child

        if( root->left != NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root->data = mini ;
            root->right = deleteFromBst(root->right,mini);
            return root ;
        }
    }
    else if (root->data > val)
    {
        root->left = deleteFromBst(root->left, val);
        return root;
    }
    else if (root->data < val)
    {
        root->right = deleteFromBst(root->right, val);
        return root;
    }
}

int main()
{
    Node *root = NULL;
    cout << "Enter Data For BST" << endl;
    dataforBst(root);
    cout << endl
         << "Level Order" << endl;
    levelOrder(root);
    cout << endl
         << "pre Order" << endl;
    preorder(root);
    cout << endl
         << "Post Order" << endl;
    postorder(root);
    cout << endl
         << "in Order" << endl;
    inorder(root);

    cout << endl;
    cout << "Minimum Value of BST = " << minVal(root)->data << endl;
    cout << "Maximum Value of BST = " << maxVal(root)->data << endl;

    root = deleteFromBst(root,90);
    cout << endl
         << "Level Order" << endl;
    levelOrder(root);
    root = deleteFromBst(root,110);
    cout << endl
         << "Level Order" << endl;
    levelOrder(root);
    root = deleteFromBst(root,20);
    cout << endl
         << "Level Order" << endl;
    levelOrder(root);

    return 0;
}