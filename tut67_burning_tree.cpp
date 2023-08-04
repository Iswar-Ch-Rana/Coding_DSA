/**************************** Burning Tree ***************************/


class Solution {
  public:
    Node* createmapping(Node* root,int target,map<Node*,Node*> &parentToNode){
        queue<Node*> q ;
        q.push(root);
        
        Node * res = NULL ;
        
        parentToNode[root] = NULL ;
        
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            
            if(curr->data == target)
                res = curr ;
            
            if(curr->left){
                parentToNode[curr->left] = curr ;
                q.push(curr->left) ;
            }
            
            if(curr->right){
                parentToNode[curr->right] = curr ;
                q.push(curr->right) ;
            }
        }
        return res ;
    }
    
    int burnTree(Node* root,map<Node*,Node*> &parentToNode){
        map<Node*,bool> visited ;
        queue<Node*>q;
        
        q.push(root);
        
        visited[root] = 1 ;
        
        int ans = 0 ;
        
        while(!q.empty()){
            bool flag = 0 ;
            int size = q.size();
            
            for(int i = 0 ; i < size ; i++){
                Node* front = q.front();
                q.pop();
                
                if(front->left && !visited[front->left]){
                    flag = 1 ;
                    q.push(front->left);
                    visited[front->left] = true ;
                }
                
                if(front->right && !visited[front->right]){
                    flag = 1 ;
                    q.push(front->right);
                    visited[front->right] = true ;
                }
                
                if(parentToNode[front] && !visited[parentToNode[front]]){
                    flag = 1 ;
                    q.push(parentToNode[front]);
                    visited[parentToNode[front]] = true ;
                }
            }
            if(flag == 1)
                ans++ ;
        }
        return ans ;
    }
    
    int minTime(Node* root, int target) 
    {
        map<Node*,Node*>parentToNode ;
        Node* targetNode = createmapping(root,target,parentToNode);
        int ans= burnTree(targetNode,parentToNode);
        return ans;
    }
};

