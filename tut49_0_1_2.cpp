// Sort linked list of 0s 1s 2s

/********************* Approach 1 ***************/

// count 0  1  2

int zerocount = 0;
int onecount = 0;
int twocount = 0;
Node *temp = head;
while (temp != NULL)
{
    if (temp->data == 0)
        zerocount++;
    else if (temp->data == 1)
        onecount++;
    else if (temp->data == 2)
        twocount++;

    temp = temp->next;
}
temp = head;
while (temp != NULL)
{
    if (zerocount != 0)
    {
        temp->data = 0;
        zerocount--;
    }
    else if (onecount != 0)
    {
        temp->data = 1;
        onecount--;
    }
    else if (twocount != 0)
    {
        temp->data = 2;
        twocount--;
    }

    temp = temp->next;
}
return head;

/**************** Approach 2 ***************/

void appendAtEnd(Node *&zeroEnd, Node *curr)
{
    zeroEnd->next = curr;
    zeroEnd = curr;
}

Node *sortList(Node *head)
{
    // Write your code here.
    Node *zero = new Node(-1);
    Node *zeroEnd = zero;
    Node *one = new Node(-1);
    Node *oneEnd = one;
    Node *two = new Node(-1);
    Node *twoEnd = two;

    Node *curr = head;

    // Crate separet Node
    while (curr != NULL)
    {
        int val = curr->data;
        if (val == 0)
        {
            appendAtEnd(zeroEnd, curr);
        }
        else if (val == 1)
        {
            appendAtEnd(oneEnd, curr);
        }
        else if (val == 2)
        {
            appendAtEnd(twoEnd, curr);
        }

        curr = curr->next;
    }

    // merg those linked list
    // one list empty or not

    head = zero->next;

    zeroEnd->next = one->next;
    oneEnd->next = two->next;
    twoEnd->next = NULL;
    zero->next = NULL;
    one->next = NULL;
    two->next = NULL;

    delete zero;
    delete one;
    delete two;

    return head;
}

//// 21. Merge Two Sorted Lists

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;

        if (list2 == NULL)
            return list1;

        // if value pointend by list1 pointer is less than equal to value pointed by list2 pointer
        // we wall call recursively list1 -> next and whole list2 list.
        if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        // we will call recursive list1 whole list and list2 -> next
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
