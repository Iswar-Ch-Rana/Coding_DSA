#include <iostream>
using namespace std;

int main()
{
    // LeetCode 206 Reverse a Linked List

    /************ Approach 1 *************/

    class Solution
    {
    public:
        ListNode *reverseList(ListNode *head)
        {
            ListNode *curr = head;
            ListNode *prev = NULL;
            ListNode *forw;
            while (curr != NULL)
            {
                forw = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forw;
            }
            return prev;
        }
    };

    /************ Approach 2 Recursive *************/

    class Solution
    {
    public:
        void solve(ListNode *&head, ListNode *prev, ListNode *curr)
        {
            if (curr == NULL)
            {
                head = prev;
                return;
            }

            ListNode *forw = curr->next;
            solve(head, curr, forw);
            curr->next = prev;
        }
        ListNode *reverseList(ListNode *head)
        {
            ListNode *prev = NULL;
            ListNode *curr = head;

            solve(head, prev, curr);
            return head;
        }
    };

    /************ Approach 3 Recursive *************/

    class Solution
    {
    public:
        ListNode *reverseList(ListNode *head)
        {
            ListNode *curr = head;
            ListNode *prev = NULL;
            ListNode *forw;
            while (curr != NULL)
            {
                forw = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forw;
            }
            return prev;
        }
    };

    // 876. Middle of the Linked List

    //////////// APPROACH 1 ////////////

    class Solution
    {
    public:
        int getlen(ListNode *head)
        {
            int count = 0;
            while (head != NULL)
            {
                count++;
                head = head->next;
            }
            return count;
        }
        ListNode *middleNode(ListNode *head)
        {
            int len = getlen(head);
            int ans = len / 2;
            int i = 0;
            while (i < ans)
            {
                head = head->next;
                i++;
            }
            return head;
        }
    };

    //////////// APPROACH 2 (OPTIMISED) ////////////

    class Solution
    {
    public:
        ListNode *middleNode(ListNode *head)
        {
            if (head == NULL || head->next == NULL)
                return head;
            if (head->next->next == NULL)
                return head->next;

            ListNode *slow = head;
            ListNode *fast = head->next;

            while (fast != NULL)
            {
                fast = fast->next;
                if (fast != NULL)
                    fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    };

    return 0;
}