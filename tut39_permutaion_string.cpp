// Permutations Code Studio 

#include <bits/stdc++.h> 


void solve(vector<int> vec ,int size,vector<vector<int>> &ans,int index){
    // Base Case
    if(index >= size){
        ans.push_back(vec);
        return ;
    }

    for(int i = index ; i < size ; i++){
        swap(vec[i],vec[index]);
        solve(vec,size,ans,index+1);
        // Backtracking 
        swap(vec[i],vec[index]);
    }
}
 


vector<vector<int>> permutations(vector<int> &vec, int size) {
    // Write your code here.
    vector<vector<int>> ans ;
    int index = 0 ;
    solve(vec,size,ans,index);
    return ans;
}

