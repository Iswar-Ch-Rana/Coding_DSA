#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    // Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        // this->prev = NULL;
    }
    ~Node() {}
};

void insertNode(Node *&end, int element, int d)
{
    if (end == NULL)
    {
        Node *temp = new Node(d);
        end = temp;
        temp->next = temp;
    }
    else
    {
        // element is preasent in the list
        Node *curr = end;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *end)
{
    if (end == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *temp = end;
    do
    {
        cout << end->data << " ";
        end = end->next;
    } while (end != temp);
    cout << endl;
}

void deleteNode(int element, Node *&end)
{

    if (end == NULL)
    {
        cout << "The list is empty" << endl;
        return;
    }
    else
    {
        Node *prev = end;
        Node *curr = prev->next;
        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        // One Node linkedlist
        if (curr == prev)
        {
            end = NULL;
        }

        // >= 2 Node in Linked List
        if (end == curr)
        {
            end = prev;
        }

        if (end == curr)
        {
            end = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *end = NULL;

    insertNode(end, 5, 3);
    insertNode(end, 3, 5);
    insertNode(end, 5, 7);
    insertNode(end, 7, 9);
    insertNode(end, 5, 6);
    print(end);
    deleteNode(5, end);
    print(end);
    return 0;
}