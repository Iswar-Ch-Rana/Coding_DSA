// 2. Add Two Numbers
/************* Approcah 1 *************/

class Solution
{
public:
    void InsertAtTail(ListNode *&head, ListNode *&tail, int digit)
    {
        ListNode *temp = new ListNode(digit);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail->next = temp;
            tail = temp;
            return;
        }
    }
    // Add two linked list
    ListNode *add(ListNode *list1, ListNode *list2)
    {
        int carry = 0;
        ListNode *ansHead = NULL;
        ListNode *ansTail = NULL;
        while (list1 != NULL && list2 != NULL)
        {
            int sum = carry + list1->val + list2->val;
            int digit = sum % 10;
            InsertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
            list1 = list1->next;
            list2 = list2->next;
        }
        while (list1 != NULL)
        {
            int sum = carry + list1->val;
            int digit = sum % 10;
            InsertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
            list1 = list1->next;
        }
        while (list2 != NULL)
        {
            int sum = carry + list2->val;
            int digit = sum % 10;
            InsertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
            list2 = list2->next;
        }
        // Carry left and both list are of same size
        while (carry != 0)
        {
            InsertAtTail(ansHead, ansTail, carry);
        }
        return ansHead;
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
    /***********  main  method   **********/
    ListNode *addTwoNumbers(ListNode *list1, ListNode *list2)
    {
        // Step - 1 reverse input linked list
        list1 = Reverse(list1);
        list2 = Reverse(list2);

        //  Add two linked list
        ListNode *ans = add(list1, list2);

        // ans = Reverse(ans);
        return ans;
    }
};
