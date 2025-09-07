class Solution {
    Node *t;
  public:
  
    Solution(){
        t=NULL;
    }
    
    int fun(Node * root,int &mx,int target)
    {
        if(root==0)
            return 0;
        if(root->data==target){
            t=root;
            return -1;
        }
        int l=fun(root->left,mx,target);
        int r=fun(root->right,mx,target);
        
        if(l<0)
        {
            mx=max(mx,abs(l)+r);
            return l-1;
        }
        else if(r<0)
        {
            mx=max(mx,abs(r)+l);
            return r-1;
        }
        
        return 1+max(l,r);
    }
    
    int height(Node * t)
    {
        if(t==0)
            return 0;
        int l=height(t->left);
        int r=height(t->right);
        
        return 1+max(l,r);
    }
    
    int minTime(Node* root, int target) {
        int mx=0;
        fun(root,mx,target);
        return max(mx,height(t)-1);
        
    }
};