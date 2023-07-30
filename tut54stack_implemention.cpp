/*
stack<int> st ;

    st.push(2) ;
    st.push(4) ;

    st.pop() ;
    cout<< "Printing the pop element "<<  st.top() << endl ;
    if (st.empty()) {
        cout << "Stack is empty" << endl ;
    }
    else {
        cout << "Stack is not empty" << endl ;
    }


    cout << "Size of stack = "<< st.size() << endl ;
*/

#include <iostream>
// #include <stack>

using namespace std ;

class Stack{
    public:
    int size ;
    int top ;
    int *arr ;
    Stack(int size){
        this->size = size ;
        arr = new int[size];
        top = -1 ;
    }
    void push(int element){
        if (size - top > 1) {
            top++;
            arr[top] = element ;    
        }
        else {
        cout << "Stack Overflow" << endl ;
        }
    }
    void pop(){
        if (isEmpty()) {
            cout << "Stack Unerflow" << endl ;
        }else {
            top--;
            cout << "pop successful" << endl ;
        }
    }
    int peek(){
        if(isEmpty()){
            cout << "Stack is empty" << endl ;
            return -1;
        }
        else {
            return arr[top];
        }
    }

    bool isEmpty(){
        if (top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
};




int main(){
    Stack st (5);
    st.push(22);
    st.push(45);
    st.push(78);
    cout << st.peek() << endl ;
    st.pop() ;
    cout << st.peek() << endl ;

    return 0;
}