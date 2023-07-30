




/************* The Celebrity Problem *************/

class Solution 
{
    private:
    bool knows(vector<vector<int> >& M,int a,int b){
        if(M[a][b] == 1)
            return true ;
        else
            return false ;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s ;
        // Pushing all the element to stack
        for(int i = 0 ; i < n ; i++)
            s.push(i) ;
            
        while(s.size() > 1){
            int a = s.top() ;
            s.pop();
            
            int b = s.top() ;
            s.pop();
            
            if(knows(M,a,b))
                s.push(b);
            else
                s.push(a);
        }
        int candidate = s.top();
        
        // bool rowCheck = false ;
        int zeroCount = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(M[candidate][i] == 0)
                zeroCount++ ;
        }
        
        // bool colCheck = false ;
        int oneCount = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(M[i][candidate] == 1)
                oneCount++ ;
        }
        if(zeroCount == n && oneCount == n-1)
            return candidate ;
        else
            return -1 ;
    }
};


/********** 85. Maximal Rectangle *************/


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
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> heights(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') {
                    heights[i][j] = 0;
                } else {
                    heights[i][j] = (i > 0) ? heights[i - 1][j] + 1 : 1;
                }
            }
        }

        int area = largestRectangleArea(heights[0]);
        for (int i = 1; i < n; i++) {
            area = max(area, largestRectangleArea(heights[i]));
        }
        return area;
    }
};

