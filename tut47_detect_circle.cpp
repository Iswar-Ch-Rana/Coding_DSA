#include <iostream>
#include <map>
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

// Cycle Is preasent or not tut 47

bool isCircular(Node *head)
{
    if (head == NULL)
    {
        return false;
    }

    Node *temp = head;
    map<Node *, bool> visited;
    while (temp != NULL)
    {
        // Circular
        if (visited[temp] == true)
        {
            // cout << "hello" << endl ;
            cout << "preasent on" << temp->data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// Floyds cycle detection algorithm

Node *FloyedDetectAlgo(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && slow != NULL)
    {
        slow = slow->next;
        fast = fast->next;

        if (fast != NULL)
            fast = fast->next;
        // cout << "Hello "<< endl ;
        if (fast == slow)
            return slow;
    }
    return NULL;
}

Node *GetStartNode(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *intersection = FloyedDetectAlgo(head);
    Node *slow = head;
    Node *fast = intersection;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

void RemoveLoop(Node* head){
    if(head == NULL)
        return ;

    Node * startofLoop = GetStartNode(head) ;
    Node * temp = startofLoop ;
    while (temp->next != startofLoop)
    {
        temp = temp->next ;
    }
    temp->next = NULL ;
}

int main()
{
    Node *end = NULL;

    insertNode(end, 5, 3);
    Node *head = end;
    insertNode(end, 3, 5);
    insertNode(end, 5, 7);
    insertNode(end, 7, 9);
    insertNode(end, 5, 6);
    print(end);
    // deleteNode(5, end);
    // print(end);
    if (FloyedDetectAlgo(head) == NULL)
    {
        cout << "Not a cycle" << endl;
    }
    else
        cout << "Cycle is preasent " << endl;

    cout << "Starting at = " << GetStartNode(head)->data << endl;



    // Remove loop
    RemoveLoop(head);
    // print(end);
    if (FloyedDetectAlgo(head) == NULL)
    {
        cout << "Not a cycle" << endl;
    }
    else
        cout << "Cycle is preasent " << endl;
    return 0;
}