#include <iostream>
using namespace std;

// Doubly Linked List


class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node(){
        cout << "Memory Free" << endl ;
    }
};

// Traversing the linked List
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Get The Length Of Linked List
int getLength(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Insert at begin of the linked list
void InstertAtBegin(Node *&head, Node *&end, int d)
{
    // Creating a new node
    Node *temp = new Node(d);

    // 1st Node creation
    if (head == NULL)
    {
        head = temp;
        end = temp;
        return;
    }
    else
    {
        // Connect with head
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
}

// Insert at end of Linked list
void InsertAtEnd(Node *&end, int d)
{
    // Get New Node
    Node *temp = new Node(d);

    // Join the end
    temp->prev = end;
    end->next = temp;
    end = temp;
}

// Insert at Any position
void InsertAtPosition(Node *&head, Node *&end, int d, int position)
{
    if (position == 1)
    {
        InstertAtBegin(head,end, d);
        return;
    }
    else
    {
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

        Node *newNode = new Node(d);
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Delete The node of a linked list
void DeletePosition(int pos, Node *&head)
{
    if (pos == 1)
    {
        Node *temp = head;
        head = temp->next;
        temp->next = NULL ;
        head->prev = NULL ;
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
        curr->prev = NULL ;
        prev->next = curr->next;
        curr->next = NULL;
        // curr->next->prev = prev ;
        delete curr;
    }
}


int main()
{
    Node *head = NULL;
    Node *end = NULL;

    InstertAtBegin(head, end, 30);
    InstertAtBegin(head, end, 20);
    InstertAtBegin(head, end, 10);
    InsertAtEnd(end, 50);
    InsertAtPosition(head, end, 60, 5);
    InsertAtPosition(head, end, 25, 3);

    print(head);
    DeletePosition(3,head);
    DeletePosition(5,head);

    print(head);
    cout << "length Of linked list = " << getLength(head) << endl;
    return 0;
}