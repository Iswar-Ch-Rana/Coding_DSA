/*  Leet Code 7. Reverse Integer
#include <bits/stdc++.h>
using namespace std;

int main ()
{
        int x;
        cin >> x ;
        int num = 0 ;
        while(x != 0)
        {
            int digit = x%10 ;
            if ((num > INT_MAX/10) || (num < INT_MIN/10))
            {
                return 0 ;
            }
            num = (num *10)+digit ;
            x = x/10 ;
        }
        cout << num << endl ;
    }
*/
// Leet Code 1009. Complement of Base 10 Integer
#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
    int x , i = 0 , num  = 0,digit;
    cin >> x ;
    while (x != 0)
    {
        digit = 1- (x & 1) ; 
        num = num + digit * pow(10,i);
        i++ ;
        x = x>>1 ;
    }
    cout << num << endl ;
    
    return 0 ;
}


















Problems
Courses
Job-a-ThonMEGA
Contests
POTD

Refresh

Time (IST)	Status	Lang	Test Cases	Code
2023-06-17 17:05:40	Correct	cpp	1076 / 1076	View
2023-06-17 16:59:19	RunTime Error	cpp	0 / 1076	View
2023-06-17 16:53:49	Wrong	cpp	2 / 1076	View
C++ (g++ 5.4)
Average Time: 20m






 

Custom Input
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node * Reverse(Node * temp){
        Node * curr = temp ;
        Node * prev = NULL ;
        Node * forw = NULL ;
        while(curr != NULL){
            forw = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = forw ;
        }
        return prev ;
    }
    Node * findMid(Node * head){
        Node * slow = head ;
        Node * fast = head->next ;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next ;
            fast = fast->next->next ;
        }
        return slow ;
    }
    bool isPalindrome(Node *head)
    {
        if(head->next == NULL && head == NULL)
            return true ;
        //Your code here
        Node * mid = findMid(head);
        mid->next = Reverse(mid->next);
        Node * left = head ;
        Node * right = mid->next ;
        // mid->next = NULL ;
        while(right != NULL && left != NULL){
            if(right->data != left->data)
                return false ;
            right = right->next ;
            left = left->next ;
        }
        return true ;
    }
};
