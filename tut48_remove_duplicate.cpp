// 83. Remove Duplicates from Sorted List

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *curr = head;

        while (curr != NULL)
        {

            if ((curr->next != NULL) && (curr->val == curr->next->val))
            {

                ListNode *next_next = curr->next->next;
                ListNode *rem = curr->next;
                delete (rem);
                curr->next = next_next;
            }
            else
            {
                curr = curr->next;
            }
        }
        return head;
    }
};

// Remove Duplicates From an Unsorted Linked List

Node *removeDuplicates(Node *&head)
{
    // Write your code here
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;
    unordered_map<int, bool> visited;
    while (temp != NULL)
    {

        if (visited[temp->data] == true)
        {
            prev->next = temp->next;
            temp = temp->next;
        }
        else
        {
            visited[temp->data] = true;
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}
