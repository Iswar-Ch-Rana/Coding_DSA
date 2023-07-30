
/************** Reverse a string using stack **************/

#include <iostream>
#include <stack>
using namespace std;

int main() {
  string str = "babbar";

  stack<char> s;

  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];
    s.push(ch);
  }

  string ans = "";

  while (!s.empty()) {
    char ch = s.top();
    ans.push_back(ch);

    s.pop();
  }

  cout << "answer is: " << ans << endl;

  return 0;
}

/********* 20. Valid Parentheses  *********/

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
      // opening braces
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        st.push(s[i]);
      } else {
        if (!st.empty()) {
          // check
          char top = st.top();
          if ((top == '(' && s[i] == ')') || (top == '{' && s[i] == '}') ||
              (top == '[' && s[i] == ']')) {
            st.pop();
          } else {
            return false;
          }
        } else {
          return false;
        }
      }
    }
    return st.empty();
  }
};


/***** Delete middle element from stack *****/


#include <bits/stdc++.h>
void solve(stack<int>&st , int n, int count){
   // Base Case 
   if(count == n/2){
      st.pop();
      return;
   }

   int num = st.top();
   st.pop();

   //Recursive Call
   solve(st, n, count+1);
   
   st.push(num);
}


void deleteMiddle(stack<int>&st, int N){
	
   int count  = 0 ;
   solve(st,N,count);
   
}

/******** Insert An Element At Its Bottom In A Given Stack ********/


#include <bits/stdc++.h> 

void solve(stack<int>& st, int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }

    int num = st.top();
    st.pop();

    solve(st, ele);

    st.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    ios::sync_with_stdio(0);
    solve(myStack,x);
    return myStack;
}

/********** Reverse Stack Using Recursion  **********/
void InsrtBottom(stack<int> &st,int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }

    int num = st.top();
    st.pop();

    InsrtBottom(st, ele);

    st.push(num);
}


void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty()){
        return ;
    }

    int val = stack.top();
    stack.pop();
    reverseStack(stack);

    InsrtBottom(stack,val);
}

/********* Sort a Stack  *********/

#include <bits/stdc++.h> 

void sortedInsert(stack<int> &stack,int num){
	if(stack.empty() || stack.top() < num){
		stack.push(num) ;
		return ;
	}

	int n = stack.top();
	stack.pop();

	sortedInsert(stack, num);
	stack.push(n) ;
}

void sortStack(stack<int> &stack)
{
	// Base case
	if(stack.empty()){
		return ;
	}

	int num = stack.top();
	stack.pop() ;

	sortStack(stack) ;

	sortedInsert(stack,num);
}


/******** Redundant Brackets  *********/

#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char>st ;

    for(int i = 0;  i < s.length() ;i++){
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*' ){
            st.push(ch);
        }
        else{
            if(ch == ')'){
                bool redundant = true ;
                while(st.top() != '('){
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '/' || top == '*' ){
                        redundant = false ;
                    }
                    st.pop();
                }
                if(redundant == true)
                    return true;
                st.pop();
            }
        }
    }
    return false ;
}


/********* Minimum Cost To Make String Valid  *********/

#include <bits/stdc++.h> 
int findMinimumCost(string str) {

  // Odd Case 
  if(str.length()%2 == 1 ){
    return -1 ;
  }
  // Removeing valid part 
  stack<char>st ;
  for(int i= 0 ;i < str.length() ; i++){
    if(str[i] == '{'){
      st.push(str[i]);
    }
    else{
      if(!st.empty() && st.top() == '{'){
        st.pop();
      }
      else{
        st.push(str[i]);
      }
    }
  }
  // stack contain invalid expression now
  int a = 0 , b = 0;
  while(!st.empty()){
    if(st.top() == '{')
      a++;
    else
      b++ ;
    st.pop();
  }
  int ans = (a+1)/2 + (b+1)/2;
  return ans ;
}


