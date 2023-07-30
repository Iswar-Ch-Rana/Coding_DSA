/* 234. Palindrome Linked List


Time = O(n)
Space = O(n)

*/

class Solution
{
public:
    bool palindrom(vector<int> arr)
    {
        int start = 0;
        int end = arr.size() - 1;
        while (start <= end)
        {
            if (arr[start] != arr[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    bool isPalindrome(ListNode *head)
    {
        ListNode *temp = head;
        vector<int> arr;
        while (temp != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        bool ans = palindrom(arr);
        return ans;
    }
};

/*
Time = O(n)
Space = O(1)
*/

class Solution
{
public:
    // get the middle Node
    ListNode *getMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    // reverse the nodes
    ListNode *Reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *forw = NULL;

        while (curr != NULL)
        {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {

        if (head->next == NULL && head == NULL)
            return true;

        ListNode *mid = getMid(head);
        mid->next = Reverse(mid->next);

        ListNode *head1 = head;
        ListNode *head2 = mid->next;

        while (head2 != NULL)
        {
            if (head1->val != head2->val)
                return false;

            head1 = head1->next;
            head2 = head2->next;
        }

        mid = getMid(head);
        mid->next = Reverse(mid->next);

        return true;
    }
};
