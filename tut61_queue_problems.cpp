/***************** Qs = 1  Queue Reversal *****************/

// Approach 1 

class Solution
{
    public:
    void reverse(queue<int>& q){
        if(q.empty())
            return ;
        int ele = q.front();
        q.pop() ;
        reverse(q) ;
        q.push(ele);
    }
    queue<int> rev(queue<int> q)
    {
        reverse(q) ;
        return q ;
    }
};

// Approach 2 Using stack


class Solution
{
    queue<int> rev(queue<int> q)
    {
        queue<int> ans ;
        stack<int>st ;
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            st.push(ele);
        }
        while(!st.empty()){
            int ele = st.top();
            st.pop();
            ans.push(ele);
        }
        return ans ;
    }
};

/***************** Qs = 2  First negative integer in every window of size k *****************/



vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
    vector<long long> ans ;
    deque<long long int> dq ;
    // process the first window of k size 
    for(int i = 0 ; i < K ; i++){
        if(A[i] < 0)
            dq.push_back(i);
    }
    
    // Storing the answer of 1st k size window
    if(dq.size() > 0){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
    
    // Doing this for other element
    for(int i = K ; i < N ; i++){
        // remove element
        if(!dq.empty() && i - dq.front() >= K){
            dq.pop_front() ;
        }
        
        // adding the other elements
        if(A[i] < 0)
            dq.push_back(i);
            
        // ans store
        if(dq.size() > 0){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans ;
}





/***************** Qs = 3  Reverse First K elements of Queue *****************/

queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int> st ;
    for(int i = 0 ; i < k ; i++){
        int ele = q.front();
        q.pop();
        st.push(ele);
    }
    
    // add the element of stack in queue
    while(!st.empty()){
        int ele = st.top();
        st.pop() ;
        q.push(ele) ;
    }
    int x = q.size() - k ;
    while(x--){
        int ele = q.front();
        q.pop();
        q.push(ele) ;
    }
    return q ;
}




/***************** Qs = 4  First non-repeating character in a stream *****************/


class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char> q;
		    unordered_map<char,int> mp;
		    string ans = "";
		    for(int i=0;i<A.size();i++){
		        mp[A[i]]++;
		        if(mp[A[i]] == 1) q.push(A[i]);
		        while(!q.empty()&&mp[q.front()]!=1){
		            q.pop();
		        }
		        if(q.empty()) ans += '#';
		        else{
		            ans += q.front();
		        }
		    }
	    return ans;
	}
};



/***************** Qs = 5 134. Gas Station *****************/


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0 ;
        int defi = 0 ;
        int bal = 0 ;

        for(int i = 0 ; i < gas.size() ; i++){
            bal += gas[i] - cost[i] ;
            if(bal < 0){
                defi += bal ;
                start = i+1 ;
                bal = 0 ;
            }
        }
        if(defi + bal >= 0)
            return start ;
        else
            return -1 ;
    }
};



/*********** Interleave the First Half of the Queue with Second Half  ************/



class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        int n = q.size()/2;
        stack<int> s;
        vector<int> ans;
        
        //push half element to stack
        for (int i=0; i<n; i++){
            s.push(q.front());
            q.pop();
        }
        
        //pop half element to queue
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }
        
        //move front half element to end half element in queue
        for (int i=0; i<n; i++){
            q.push(q.front());
            q.pop();
        }
        
        //push half element to stack
        for (int i=0; i<n; i++) {
            s.push(q.front());
            q.pop();
        }
        
        //again push to queue in interleave
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
            q.push(q.front());
            q.pop();
        }
        
        //push queue in ans
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};


/***********  k Queues in a single array *************/



#include<iostream>
using namespace std;

class kQueue {

    public:
        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int freeSpot;
        int *next;

    public:
        kQueue(int n, int k) {
            this -> n = n;
            this -> k = k;
            front = new int[k];
            rear = new int[k];
            for(int i=0; i<k; i++) {
                front[i] = -1;
                rear[i] = -1;
            }

            next = new int[n];
            for(int i=0; i<n; i++) {
                next[i] = i+1;
            }
            next[n-1] = -1;
            arr = new int[n];
            freeSpot = 0;
        }    

        void enqueue(int data, int qn) {

            //overflow
            if( freeSpot == -1) {
                cout << "No Empty space is present" << endl;
                return;
            }

            //find first free index
            int index = freeSpot;

            //update freespot
            freeSpot = next[index];

            //check whther first element
            if(front[qn-1] == -1){
                front[qn-1] = index;
            }
            else{
                //link new element to the prev element
                next[rear[qn-1]] = index;
            }

            //update next
            next[index] = -1;

            //update rear
            rear[qn-1] = index;

            //push element
            arr[index] = data;
        }

        int dequeue(int qn) {
            //underflow 
            if(front[qn-1] == -1)
            {
                cout << "Queue UnderFlow " << endl;
                return -1;
            }

            //find index to pop
            int index = front[qn-1];

            //front ko aage badhao
            front[qn-1] = next[index];

            //freeSlots ko manage karo
            next[index] = freeSpot;
            freeSpot = index;
            return arr[index];
        }

};

int main() {

    kQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15,1);
    q.enqueue(20, 2);
    q.enqueue(25,1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    cout << q.dequeue(1) << endl;

    return 0;
}


/********** Sum of min and max in an array of k size window **********/


#include<iostream>
#include<queue>
using namespace std;

int solve(int *arr, int n, int k) {

    deque<int> maxi(k);
    deque<int> mini(k);

    //Addition of first k size window

    for(int i=0; i<k; i++) {

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;

    ans += arr[maxi.front()] + arr[mini.front()];

    //remaining windows ko process karlo
    for(int i=k; i<n; i++) {

        

        //next window

        //removal
        while(!maxi.empty() && i - maxi.front() >=k) {
            maxi.pop_front();
        }

        while(!mini.empty() && i - mini.front() >=k) {
            mini.pop_front();
        }

        //addition

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);    

        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}

int main() {


    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, 7, k) << endl;


    return 0;
}