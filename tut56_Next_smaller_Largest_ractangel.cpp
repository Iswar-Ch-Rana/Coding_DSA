
/********** Next Smaller Element ********/

#include <stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int>ans(n) ;
    stack<int> st ;
    st.push(-1);
    for(int i = n-1 ; i >= 0 ; i--){
        int ele = arr[i];
        while(st.top() >= ele ){
            st.pop();
        } 
        ans[i] = st.top();
        st.push(ele);
    }
    return ans ;
}

/********** 84. Largest Rectangle in Histogram *********/

class Solution {
public:
    vector<int>nextSmallEle(vector<int>arr , int n){
        stack<int> st ;
        st.push(-1);
        vector<int>ans(n) ;
        for(int i = n-1 ; i >= 0 ; i--){
            int ele = arr[i];
            while((st.top() != -1) && (arr[st.top()] >= ele) ){
                st.pop();
            } 
            ans[i] = st.top();
            st.push(i);
        }
        return ans ;
    }
    vector<int>prevSmallEle(vector<int>arr , int n){
        stack<int> st ;
        st.push(-1);
        vector<int>ans(n) ;
        for(int i = 0 ; i < n ; i++){
            int ele = arr[i];
            while((st.top() != -1) && (arr[st.top()] >= ele) ){
                st.pop();
            } 
            ans[i] = st.top();
            st.push(i);
        }
        return ans ;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int>next(n);
        vector<int>prev(n);
        
        prev = prevSmallEle(heights,n);
        next = nextSmallEle(heights,n);

        int area = INT_MIN ;
        for(int i = 0;i < n ; i++){
            if(next[i] == -1)
                next[i] = n ;

            int l = heights[i];

            int b = next[i] - prev[i] -1 ; 
            
            int newArea = l*b ;
            area = max(area ,newArea);
        }
        return area;
    }
};
