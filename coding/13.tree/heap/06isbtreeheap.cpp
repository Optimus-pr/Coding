class Solution {
    int cnt;
  public:
  
    Solution()
    {
        cnt=0;
    }
    
    bool ismaxHeap(Node * root)
    {
        queue<Node *> q;
        q.push(root);
        bool flag=true;
        
        while(!q.empty())
        {
            Node * t=q.front();
            q.pop();
            cnt++;
            
            if(t->left)
               if(t->data > t->left->data) 
                    q.push(t->left);
                else
                    flag=false;
            if(t->right)
               if(t->data > t->right->data) 
                    q.push(t->right);
                else
                    flag=false;
        }
        return flag;
    }
    
    bool isComplete(Node * root)
    {
        queue<pair<Node *,int> > q;
        q.push({root,0});
        
        while(!q.empty())
        {
            Node *t=q.front().first;
            int ind=q.front().second;
            q.pop();
            
            if(ind>=cnt)
                return false;
            
            if(t->left)
                q.push({t->left,2*ind+1});
            if(t->right)
                q.push({t->right,2*ind+2});
        }
        return true;
    }
  
    bool isHeap(Node* tree) {
        // code here
        return ismaxHeap(tree) && isComplete(tree);
    }
};