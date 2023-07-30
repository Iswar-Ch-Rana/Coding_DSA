#include <iostream>
using namespace std;

// Single Linked List


class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        cout << "Memory is free now" << endl ;
    }
};

void InsertAtEnd(Node *&end, int d)
{
    // create a new node
    Node *temp = new Node(d);

    // Insert at end
    end->next = temp;
    end = temp;
}

void InsertAtBegin(Node *&head, int d)
{
    // create a new node
    Node *temp = new Node(d);

    // insert at begin
    temp->next = head;
    head = temp;
}

void InsertAtPoint(Node *&head, Node *&end, int position, int d)
{
    if (position == 1)
    {
        InsertAtBegin(head, d);
        return;
    }
    // create a new node
    Node *newNode = new Node(d);

    Node *temp = head;
    int i = 1;
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp->next == NULL)
    {
        InsertAtEnd(end, d);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

void DeletePosition(int pos, Node *&head)
{
    if (pos == 1)
    {
        Node *temp = head;
        head = temp->next;
        temp->next = NULL ;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int i = 1;
        while (i < pos)
        {
            prev = curr ;
            curr = curr->next ;
            i++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;
    // pointing head to 1st Node
    Node *head = node1;
    Node *end = node1;

    InsertAtBegin(head, 20);
    InsertAtBegin(head, 30);
    InsertAtEnd(end, 40);

    print(head);

    InsertAtPoint(head, end, 5, 5);
    print(head);

    // DeletePosition(1, head);
    // print(head);

    DeletePosition(5, head);
    print(head);

    return 0;
}