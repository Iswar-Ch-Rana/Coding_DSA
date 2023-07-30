// 148. Sort List
/********** Merge Sort **********/



class Solution {
public:

    ListNode * findMid(ListNode * temp){
        ListNode* slow = temp ;
        ListNode* fast = temp->next ;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next ;
            fast = fast->next->next ;
        }
        return slow ;
    }

    ListNode * Merge(ListNode *left,ListNode *right){
        if(left == NULL)
            return right ;
        if(right == NULL)
            return left ;

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans ;

        while(left != NULL && right != NULL){
            if(left->val > right->val){
                temp->next = right; 
                temp = temp->next ;
                right = right->next ;
            }else{
                temp->next = left; 
                temp = temp->next ;
                left = left->next ;
            }
        }
        while(left != NULL){
            temp->next = left; 
            temp = temp->next ;
            left = left->next ;
        }
        while(right != NULL){
            temp->next = right; 
            temp = temp->next ;
            right = right->next ;
        }
        ans = ans->next ;

        return ans ;
    }


    ListNode* sortList(ListNode* head) {
        ios_base::sync_with_stdio(false);
        // Base Case
        if(head == NULL || head->next == NULL)
            return head ;
        
        ListNode* mid = findMid(head) ;

        // devide linked list in two parts
        ListNode * left = head ;
        ListNode * right = mid->next ;
        mid->next = NULL ;


        // sorting left and right of the list
        left = sortList(left) ;
        right = sortList(right) ;

        // Merge two linked list
        ListNode * result = Merge(left,right);

        return result ;
    }
};
